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
#include "SoundPlaylist.h"

using namespace MINX;
using namespace MINX::Media;

SoundPlaylist::SoundPlaylist()
{
	songFiles = std::vector<char*>();
	doShuffle = false;
	songIndex = 0;
}

void SoundPlaylist::AddSound(char* fileLocation)
{
	songFiles.push_back(fileLocation);
}

void SoundPlaylist::Play()
{
	if(currentSong && !songDeleted)
	{
		currentSong->Stop();
 		delete currentSong;
		currentSong = NULL;
		songDeleted = true;
	}

	if(doShuffle)
	{
		songIndex = rand() % songFiles.size();
	}

	currentSong = new SoundFile(songFiles[songIndex]);
	songDeleted = false;
	currentSong->Play();
	++songIndex;
	if(songIndex >= songFiles.size())
	{
		songIndex = 0;
	}
}

void SoundPlaylist::Stop()
{
	if(currentSong && !songDeleted)
	{
		currentSong->Stop();
		delete currentSong;
		songDeleted = true;
		songIndex = 0;
	}
}

