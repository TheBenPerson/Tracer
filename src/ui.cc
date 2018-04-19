/*
 *
 * https://github.com/TheBenPerson/Trace
 *
 * Copyright (C) 2018 Ben Stockett <thebenstockett@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <math.h>
#include <QApplication>
#include <QColor>
#include <QColorDialog>
#include <QDialog>
#include <QFileDialog>
#include <QImage>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QObject>
#include <QPixmap>
#include <QProgressDialog>
#include <QString>
#include <QThread>

#include "color.hh"
#include "dialog_about.hh"
#include "dialog_camera.hh"
#include "dialog_main.hh"
#include "dialog_properties.hh"
#include "object.hh"
#include "tracer.hh"
#include "ui.hh"
#include "vector.hh"

static QImage image;
static Screen *screen;
static Ui::Main *uiMain;

static void saveImage(bool);
static void aboutMenu(bool);
static void cameraMenu();
static void trace(bool);

int main(int argc, char* argv[]) {

	Object::init();

	QApplication app(argc, argv);
	QMainWindow window;

	Ui::Main ui;
	uiMain = &ui;

	ui.setupUi(&window);

	Screen out;

	screen = &out;
	ui.verticalLayout->insertWidget(0, &out);

	QObject::connect(ui.actionSave, &QAction::triggered, &saveImage);
	QObject::connect(ui.actionQuit, SIGNAL(triggered()), &window, SLOT(close()));
	QObject::connect(ui.actionAbout, &QAction::triggered, &aboutMenu);
	QObject::connect(ui.buttonCamera, &QPushButton::clicked, &cameraMenu);

	ui.valThreads->setValue(QThread::idealThreadCount());

	QObject::connect(ui.buttonTrace, &QPushButton::clicked, &trace);

	window.show();
	return app.exec();

}

void Screen::mousePressEvent(QMouseEvent *event) {

	Vector ray = {

		event->x() - Tracer::dwidth,
		(Tracer::height - event->y() - 1) - Tracer::dheight,
		Tracer::dheight / tan(Tracer::fov)

	};

	ray.rotate(Tracer::rotX, Tracer::rotY);

	Object *object = Object::getObject(&Tracer::pos, &ray, NULL);
	if (!object) return;

	QDialog dialog;
	Ui::dialogProperties ui;
	ui.setupUi(&dialog);

	ui.valX->setValue(object->pos.x);
	ui.valY->setValue(object->pos.y);
	ui.valZ->setValue(object->pos.z);

	QColorDialog dialogColor;
	dialogColor.setCurrentColor(QColor(object->color.red, object->color.green, object->color.blue));
	QObject::connect(ui.buttonColor, SIGNAL(clicked()), &dialogColor, SLOT(exec()));

	ui.valReflect->setValue(object->reflect * 100);

	dialog.show();
	if (dialog.exec() == QDialog::Rejected) return;

	object->pos.x = ui.valX->value();
	object->pos.y = ui.valY->value();
	object->pos.z = ui.valZ->value();

	QColor color = dialogColor.currentColor();
	object->color.red = color.red();
	object->color.green = color.green();
	object->color.blue = color.blue();

	object->reflect = ui.valReflect->value() / 100.0;

}

void saveImage(bool) {

	QString path = QFileDialog::getSaveFileName(NULL, "Save as", "untitled.png", "PNG File(*.png);;");
	if (path.isNull()) return;

	image.save(path, "png");

}

void aboutMenu(bool) {

	QDialog dialog;
	Ui::dialogAbout ui;
	ui.setupUi(&dialog);

	dialog.show();
	dialog.exec();

}

void cameraMenu() {

	QDialog dialog;
	Ui::dialogCamera ui;
	ui.setupUi(&dialog);

	ui.valX->setValue(Tracer::pos.x);
	ui.valY->setValue(Tracer::pos.y);
	ui.valZ->setValue(Tracer::pos.z);

	// to degrees
	ui.valRotX->setValue((Tracer::rotX * 360) / (M_PI * 2));
	ui.valRotY->setValue((Tracer::rotY * 360) / (M_PI * 2));

	dialog.show();
	dialog.exec();

	Tracer::pos.x = ui.valX->value();
	Tracer::pos.y = ui.valY->value();
	Tracer::pos.z = ui.valZ->value();

	// to radians
	Tracer::rotX = (ui.valRotX->value() * (M_PI * 2)) / 360;
	Tracer::rotY = (ui.valRotY->value() * (M_PI * 2)) / 360;

}

void trace(bool) {

	int threads = uiMain->valThreads->value();

	Tracer::samples = uiMain->valSamples->value();
	Tracer::width = uiMain->valWidth->value();
	Tracer::height = uiMain->valHeight->value();
	Tracer::dwidth = Tracer::width / 2;
	Tracer::dheight = Tracer::height / 2;

	Object::shadows = uiMain->valShadows->isChecked();
	Object::reflections = uiMain->valReflections->isChecked();

	image = QImage(Tracer::width, Tracer::height, QImage::Format_RGB888);

	int pixels = Tracer::height * Tracer::width;
	pixels /= threads;

	QProgressDialog dialog("Tracing...", "Cancel", 0, Tracer::height * Tracer::width);
	dialog.setValue(0);

	int progress = 0;

	for (int i = 0; i < threads; i++) {

		Tracer *tracer = new Tracer(pixels * i, pixels, &progress);

		QObject::connect(tracer, SIGNAL(setValue(int)), &dialog, SLOT(setValue(int)));
		QObject::connect(&dialog, SIGNAL(canceled()), tracer, SLOT(cancel())); // TODO: not working

		tracer->start();

	}

	dialog.exec();
	screen->setPixmap(QPixmap::fromImage(image));

}

void setPixel(int x, int y, Color *color) {

	if (color->red < 0) color->red = 0;
	if (color->green < 0) color->green = 0;
	if (color->blue < 0) color->blue = 0;

	if (color->red > 255) color->red = 255;
	if (color->green > 255) color->green = 255;
	if (color->blue > 255) color->blue = 255;

	uchar *line = image.scanLine(Tracer::height - y - 1);
	int offset = x * 3;

	line[offset] = color->red;
	line[offset + 1] = color->green;
	line[offset + 2] = color->blue;

}
