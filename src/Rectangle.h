/*
MINX - A C++ Graphics and Input Wrapper Library
Copyright (C) 2013-2014  MINX Team

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef Rectangle_H_
#define Rectangle_H_

#include "API.h"

#include <cmath>
namespace MINX
{
	/** A Rectangle struct
	*/
	struct MINX_API Rectangle
	{
		/** Creates a new instance of Rectangle with all 0 values
		*/
		Rectangle();

		/** Creates a new instance of Rectangle
		*	@param x The X coordinate of the Rectangle
		*	@param y the Y coordinate of the Rectangle
		*	@param width The Width of the Rectangle
		*	@param height The Height of the Rectangle
		*/
		Rectangle(double x, double y, double width, double height);
		/** Returns the Area of the Rectangle
		*/
		double Area();
		/** The X location of the Rectangle
		*/
		double X;
		/** The Y location of the Rectangle
		*/
		double Y;
		/** The Width of the Rectangle
		*/
		double Width;
		/** The Hight of the Rectangle
		*/
		double Height;
		/** The Y coordinate of the Top Edge of the Rectangle
		*/
		double Top();
		/** The Y coordinate of the Bottom Edge of the Rectangle
		*/
		double Bottom();
		/** The X coordinate of the Left Edge of the Rectangle
		*/
		double Left();
		/** The X coordinate of the Right Edge of the Rectangle
		*/
		double Right();
		/** Checks if one Rectangle intersects another
		*	@param rect2 The Rectangle to Check for Intersection against
		*	@returns Whether or not the two Rectangles intersect
		*/
		bool Intersects(Rectangle* rect2);
	};
}
#endif
