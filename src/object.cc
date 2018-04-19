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

#include <float.h>
#include <math.h>
#include <QColor>
#include <vector>

#include "color.hh"
#include "object.hh"
#include "plane.hh"
#include "sphere.hh"
#include "vector.hh"

Vector Object::lamp(0, 200, 0);
Color Object::lampColor(255, 0, 0);
bool Object::shadows;
bool Object::reflections;
std::vector<Object*> Object::objects;

void Object::init() {

	Vector pos(0, 0, 0);

	Vector size;
	Vector rot;
	new Plane(&pos, &size, &rot);

	for (double i = 0; i < M_PI * 8; i += M_PI / 8.0) {

		Color color;

		int c = ((int) (i / (M_PI / 8.0))) % 6;
		int dc = 255 * (i / (M_PI * 8));

		if (c == 0) color = Color(255, dc, 0);
		if (c == 1) color = Color(255 - dc, 255, 0);
		if (c == 2) color = Color(0, 255, dc);
		if (c == 3) color = Color(0, 255 - dc, 255);
		if (c == 4) color = Color(i, 0, 255);
		if (c == 5) color = Color(255, 0, 255 - dc);

		pos = Vector(cos(i) * 150, (i * (400 / (M_PI * 8))) + 25, 1000 + (sin(i) * 150));
		new Sphere(25, &pos, &color, i / (M_PI * 8));

	}

}

Object::Object(Vector *pos, Color *color, double reflect): pos(*pos), color(*color), reflect(reflect) {

	objects.push_back(this);

}

Object* Object::getObject(Vector *eye, Vector *ray, Vector *point) {

	Object *target = NULL;
	double closest = DBL_MAX;

	// get object closest to eye
	for (unsigned int i = 0; i < objects.size(); i++) {

		Object *object = objects[i];

		Vector temp;
		bool result = object->getIntersect(eye, ray, &temp);
		if (!result) continue;

		// eye to intersection
		Vector full = temp - *eye;
		double dist = full.getLen();

		if (dist >= closest) continue;

		if (point) *point = temp;
		target = object;
		closest = dist;

	}

	return target;

}

bool Object::getColor(Vector *eye, Vector *ray, Color *color) {

	// point of intersection
	Vector point;
	Object *target = getObject(eye, ray, &point);

	// if ray doesn't hit anything
	if (!target) return false;

	Vector normal;
	target->getNormal(&point, &normal);

	bool shadow = false;

	if (shadows) {

		// lamp to point
		Vector light = point - lamp;
		double dist = light.getLen();

		// see if we're closest to lamp
		for (unsigned int i = 0; i < objects.size(); i++) {

			Object *object = objects[i];
			if (object == target) continue;

			Vector temp;
			bool result = object->getIntersect(&lamp, &light, &temp);
			if (!result) continue;

			temp = temp - lamp;

			double len = temp.getLen();
			if (len < dist) shadow = true;

		}

	}

	// point to lamp
	Vector light = lamp - point;
	light.normalize();

	double diffuse = Vector::dot(&light, &normal);
	if (diffuse < 0) diffuse = 0;

	Color base;
	target->getColor(&point, &base);

	Color ambient = base * .1;

	*color = base * diffuse;
	*color += ambient;

	Color shade = base * .3 * shadow;
	*color -= shade;

	if (!reflections) return true;
	if (!target->reflect) return true;

	// calculate reflection
	Vector rayp = normal * Vector::dot(ray, &normal);
	rayp *= 2;
	rayp = *ray - rayp;

	Color result;
	getColor(&point, &rayp, &result);
	Color::mix(target->reflect, color, &result, color);

	return true;

}
