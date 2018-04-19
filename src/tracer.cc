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
#include <stdlib.h>
#include <QMutex>
#include <QThread>

#include "object.hh"
#include "tracer.hh"
#include "ui.hh"
#include "vector.hh"

static QMutex mutex;

Vector Tracer::pos(0, 50, 0);
int Tracer::samples = 20;
int Tracer::width;
int Tracer::height;
double Tracer::dwidth;
double Tracer::dheight;
double Tracer::rotX = (5 / 360.0) * (M_PI * 2);
double Tracer::rotY;
double Tracer::fov = 70 / 360.0;

Tracer::Tracer(int offset, int size, int *progress): offset(offset), size(size), progress(progress) {}

void Tracer::start() {

	QThread *thread = new QThread;
	moveToThread(thread);

	// start running when thread starts
	connect(thread, SIGNAL(started()), this, SLOT(run()));

	// tell thread when done
	connect(this, SIGNAL(finished()), thread, SLOT(quit()));
	connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();

}

void Tracer::run() {

	double dist = dheight / tan(fov);

	for (int p = 0; p < size; p++) {

		int x = (offset + p) % width;
		int y = (offset + p) / width;

		Color color;
		for (int i = 0; i < samples; i++) {

			double xo = (double) rand() / RAND_MAX;
			double yo = (double) rand() / RAND_MAX;

			Vector ray = {(x - dwidth) + xo, (y - dheight) + yo, dist};
			ray.rotate(rotX, rotY);
			ray.normalize();

			Color temp;
			Object::getColor(&pos, &ray, &temp);

			color += temp;

		}

		color /= samples;
		setPixel(x, y, &color);

		mutex.lock();

		(*progress)++;
		if (!(*progress % 100) || *progress == width * height) emit setValue(*progress);

		mutex.unlock();

	}

	emit finished();

}

void Tracer::cancel() {

	emit finished();

}

#include "moc_tracer.hh"
