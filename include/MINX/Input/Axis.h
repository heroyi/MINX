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
#ifndef AXIS_H_
#define AXIS_H_

#include "../API.h"

namespace MINX
{
	namespace Input{
		/** Represents an axis on an input device such as a mouse or joystick.
		 * Some axes indicate a position (a stick on a game pad), some indicate relative motion (a ball on a joypad), some possibly could indicate rotation, as in a dial.
		 * This could also be used to create a soft axis within a game.
		 */
		struct MINX_API Axis
		{
			/** Sets the value of the axis to val
			 */
			void SetValue(bool val);
			
			/** Sets the value of the axis to val
			 */
			inline void UpdateValue(bool val){SetValue(val);}
			
			/** Gets the value of the axis
			 */
			float GetValue();
			
			/** Gets the previous value of the axis
			 */
			float GetPrevValue();
			private:
				/** The current value of the axis.
				 */
				double val;
				/** The previous value of the axis.
				 */
				double prevVal;
		};
	}
}
#endif
