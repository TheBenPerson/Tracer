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

#include "sphere.hh"
#include "vector.hh"

Sphere::Sphere(double radius, Vector *pos, Color *color, double reflect): Object(pos, color, reflect), radius(radius) {}

bool Sphere::getIntersect(Vector *point, Vector *ray, Vector *out) {

	double a = pow(ray->x, 2) + pow(ray->y, 2) + pow(ray->z, 2);
	double b = 2 * ((ray->x * (point->x - pos.x)) + (ray->y * (point->y - pos.y)) + (ray->z * (point->z - pos.z)));
	double c = pow((point->x - pos.x), 2) + pow((point->y - pos.y), 2) + pow((point->z - pos.z), 2) - pow(radius, 2);

	// discriminant
	double d = (b * b) - (4 * a * c);
	if (d < 0) return false;

	double t = -b - sqrt(d);
	t /= (2 * a);

	if (t <= 0) return false;

	*out = (*ray) * t;
	*out += *point;

	return true;

}

void Sphere::getNormal(Vector *point, Vector *out) {

	*out = *point - pos;
	out->normalize();

}

void Sphere::getColor(Vector *pos, Color *color) {

	*color = this->color;

}
