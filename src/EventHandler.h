/*
    MINX - A C++ Graphics and Input Wrapper Library
    Copyright (C) 2013  MINX Team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	*/

#include "GameTime.h"
#ifndef EVENT_HANDLER_H_
#define EVENT_HANDLER_H_
namespace MINX
{
	class Game; //forward declaration to avoid dependency problems

	/** An Event Handler class
	*/
	class EventHandler
	{
		public:
			/** Creates a new instance of an event handler
			*	@param attachTo A pointer to the game object to attach to.
			*/
			EventHandler(Game * attachTo);
			/** Handles the event
			*/
			virtual void handleEvent();
		protected:
			Game * game;
	};
}
#include "Game.h"
#endif
