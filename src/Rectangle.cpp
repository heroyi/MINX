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
#include "Rectangle.h"
#include <math.h>

using namespace MINX;

Rectangle::Rectangle()
{
	X = 0;
	Y = 0;
	Width = 0;
	Height = 0;
}
Rectangle::Rectangle(double x, double y, double width, double height)
{
	X=x;
	Y=y;
	Width = width;
	Height = height;
}
double Rectangle::Area()
{
	return Width * Height;
}
double Rectangle::Top()
{
	return Y;
}
double Rectangle::Bottom()
{
	return Y + Height;
}
double Rectangle::Left()
{
	return X;
}
double Rectangle::Right()
{
	return X + Width;
}
bool Rectangle::Intersects(Rectangle* rect2)
{
	return !(
			(Bottom() < rect2->Top()) ||
			(Top() > rect2->Bottom()) ||
			(Left() > rect2->Right()) ||
			(Right() < rect2->Left()) );
}
