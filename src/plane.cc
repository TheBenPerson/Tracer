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

#include "plane.hh"
#include "vector.hh"

Plane::Plane(Vector *pos, Vector *size, Vector *rot): Object(pos, &color, .3), size(*size), rot(*rot) {}

bool Plane::getIntersect(Vector *point, Vector *ray, Vector *out) {

	if (!ray->y) return false;
	double t = (pos.y - point->y) / ray->y;

	if (t <= 0) return false;

	*out = (*ray) * t;
	*out += *point;

	return true;

}

void Plane::getNormal(Vector *point, Vector *out) {

	*out = Vector(0, 1, 0);

}

void Plane::getColor(Vector *point, Color *color) {

	int x = (int) point->x % 100;
	int z = (int) point->z % 100;

	if (x < 0) x += 100;
	if (z < 0) z += 100;

	if ((x < 50) && (z < 50)) *color = Color(143, 143, 143);
	else if ((x > 50) && (z > 50)) *color = Color(143, 143, 143);
	else *color = Color(255, 255, 255);

}
