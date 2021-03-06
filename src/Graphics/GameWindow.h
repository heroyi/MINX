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
	
#ifndef GAME_WINDOW_H_
#define GAME_WINDOW_H_

#include "../API.h"

#include <GLFW/glfw3.h>

#include "Color.h"

namespace MINX
{
	namespace Graphics
	{
		/** A class that holds the GLFW window pointer and some basic info about the window
		*/
		class MINX_API GameWindow
		{
			public:
				/** Creates a new instance of GameWindow
				*	@param width The Width of the GameWindow
				*	@param height The Height of the GameWindow
				*	@param bpp The Bits Per Pixel of the GameWindow
				*	@param flags The flags to create the GameWindow with
				*	@param fullscreen Whether or not to initialize MINX in Fullscreen mode
				*/
				GameWindow(int width, int height, bool fullscreen);
				
				/** Creates a new instance of GameWindow
				*	@param width The Width of the GameWindow
				*	@param height The Height of the GameWindow
				*	@param bpp The Bits Per Pixel of the GameWindow
				*	@param flags The flags to create the GameWindow with
				*	@param fullscreen Whether or not to initialize MINX in Fullscreen mode
				*	@param title The Title of the GameWindow
				*/
				GameWindow(int width, int height, bool fullscreen, char* title);
				/** Returns the width of the GameWindow
				 */
				inline static int GetWidth() { return width; }

				/** Returns the height of the GameWindow
				 */
				inline static int GetHeight() { return height; }
				
				/** Sets the width of the GameWindow
				 */
				static void SetWidth(int width);
				
				/** Sets the height of the GameWindow
				 */
				static void SetHeight(int height);

				/** A Pointer to the instance of the GLFWwindow
				*/
				static GLFWwindow* window;

				/** Whether or not the window size is locked
				 */
				static bool sizeLocked;
			private:
				/** The Width of the GameWindow
				*/
				static int width;
				
				/** The Height of the GameWindow
				*/
				static int height;

		};
	}
}
#endif
