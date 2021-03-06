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

#ifndef SOUND_FILE_H_
#define SOUND_FILE_H_

#include "../API.h"

#include "SFML/Audio.hpp"
#include <string>

namespace MINX
{
	namespace Media
	{
		/** A class to hold a single sound file
		*/
		class MINX_API SoundFile
		{
		public:
			/* Load a sound file from the hard disk
			*	@param fileLocation The path of the file to load.
			*/
			SoundFile(char* fileLocation);

			/* Destroy the sound file safely
			*/
			~SoundFile();

			/* unload the sound file safely
			*/
			void Unload();

			/* Start playback of the sound file
			*/
			void Play();

			/* Pause playback of the sound file
			*/
			void Pause();

			/* Stop playback of the sound file
			*/
			void Stop();

			/* Set the Playback volume of the sound file
			*	@param volume A double value from 0.0 to 100.0 for the GAIN or volume of the sound file
			*/
			void SetVolume(float volume);
		private:

			/* The volume of the sound file
			*/
			double volume;

			/** The internal sfml sound buffer
			 */
			sf::SoundBuffer soundBuffer;

			/** The internal sfml sound object
			 */
			sf::Sound sound;
		};
	}
}


#endif
