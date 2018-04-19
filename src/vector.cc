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

#include "vector.hh"

double Vector::dot(Vector *a, Vector *b) {

	return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);

}

Vector::Vector() {}
Vector::Vector(double x, double y, double z): x(x), y(y), z(z) {}

Vector Vector::operator+(Vector& vector) {

	Vector result = *this;
	result.x += vector.x;
	result.y += vector.y;
	result.z += vector.z;

	return result;

}

Vector Vector::operator-(Vector& vector) {

	Vector result = *this;
	result.x -= vector.x;
	result.y -= vector.y;
	result.z -= vector.z;

	return result;

}

Vector Vector::operator*(double val) {

	Vector result = *this;
	result.x *= val;
	result.y *= val;
	result.z *= val;

	return result;

}

void Vector::operator+=(Vector &vector) {

	x += vector.x;
	y += vector.y;
	z += vector.z;

}

void Vector::operator*=(double val) {

	x *= val;
	y *= val;
	z *= val;

}

double Vector::getLen() {

	return sqrt((x * x) + (y * y) + (z * z));

}

void Vector::normalize() {

	double len = getLen();

	x /= len;
	y /= len;
	z /= len;

}

void Vector::rotate(double rotx, double roty) {

	// rotate in the zy plane

	double before = z;

	z = (z * cos(rotx)) - (y * sin(rotx));
	y = (before * sin(rotx)) + (y * cos(rotx));


	// rotate clockwise in the xz plane

	before = x;
	roty *= -1;

	x = (x * cos(roty)) - (z * sin(roty));
	z = (before * sin(roty)) + (z * cos(roty));

}
