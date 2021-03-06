/*
    MINX - A C++ Graphics and Input Wrapper Library
    Copyright (C) 2014  MINX Team

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
#ifndef _RENDER_TARGET_H_
#define _RENDER_TARGET_H_

#include "../API.h"

#include <GL/glew.h>

#include "Texture2D.h"
#include "GameWindow.h"
#include "../Rectangle.h"

namespace MINX
{
	class MINX_API Game;
	namespace Graphics
	{
		class MINX_API RenderTarget
		{
		public:
			/** Creates a RenderTarget with the specified width and height
			 */
			RenderTarget(int width, int height);
			/** Returns a pointer to a Texture2D containing the contents of this RenderTarget
			 */
			Texture2D* GetTexture();
			/** Returns the width of the RenderTarget
			 */
			inline int GetWidth() { return width; }
			/** Returns the height of the RenderTarget
			 */
			inline int GetHeight() { return height; }
			/** Clears the contents of the RenderTarget to the specified color
			 */
			void Clear(Color clearColor);
		private:
			int width, height;
			GLuint frameBuffer;
			GLuint frameBufferTex;
			Texture2D* texture;
			friend class MINX::Game;
		};

	}

}
#include "../Game.h"
#endif
