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

#include <stdint.h>

#include "color.hh"

void Color::mix(double amount, Color *a, Color *b, Color *out) {

	Color c = *a * (1 - amount);
	Color d = *b * amount;

	*out = c + d;

}

Color::Color() {}
Color::Color(double red, double green, double blue): red(red), green(green), blue(blue) {}

Color Color::operator+(Color &color) {

	Color result = *this;
	result.red += color.red;
	result.green += color.green;
	result.blue += color.blue;

	return result;

}

Color Color::operator*(double val) {

	Color result = *this;
	result.red *= val;
	result.green *= val;
	result.blue *= val;

	return result;

}

Color Color::operator/(double val) {

	Color result = *this;
	result.red /= val;
	result.green /= val;
	result.blue /= val;

	return result;

}

void Color::operator+=(Color &color) {

	red += color.red;
	green += color.green;
	blue += color.blue;

}

void Color::operator-=(Color &color) {

	red -= color.red;
	green -= color.green;
	blue -= color.blue;

}

void Color::operator*=(double val) {

	red *= val;
	green *= val;
	blue *= val;

}

void Color::operator/=(double val) {

	red /= val;
	green /= val;
	blue /= val;

}
