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

#ifndef TRACE_OBJECT
#define TRACE_OBJECT

#include <QColor>
#include <vector>

#include "color.hh"
#include "vector.hh"

class Object {

	public:

		static Vector lamp;
		static Color lampColor;
		static bool shadows;
		static bool reflections;
		static std::vector<Object*> objects;

		Vector pos;
		double reflect;
		Color color;

		static void init();

		static Object* getObject(Vector *eye, Vector *ray, Vector *point);
		static bool getColor(Vector *point, Vector *ray, Color *color);

		Object(Vector *pos, Color *color, double reflect);
		virtual bool getIntersect(Vector *point, Vector *ray, Vector *out) = 0;
		virtual void getNormal(Vector *point, Vector *out) = 0;
		virtual void getColor(Vector *point, Color *color) = 0;

};

#endif
