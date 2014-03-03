#!/bin/bash
#    MINX - A C++ Graphics and Input Wrapper Library
#    Copyright (C) 2013-2014  MINX Team
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.

echo "Please type the directory in which you would like to create the new MINX project: "

read projectDir

echo "Please enter the name you would like to use for the source file of your new project (no extension, spaces, or non-alphanumeric characters): "

read fileName

fileName=$(echo $fileName | tr -d "[:space:].*!@#$%^&()}][{+=?/:;|~\`\"\\'<>,-")


test -d "$projectDir" || mkdir -p "$projectDir";
test -d "$projectDir/src/" || mkdir -p "$projectDir/src/";
test -d "$projectDir/bin/" || mkdir -p "$projectDir/bin/";
echo "
//AUTOGENERATED FILE: DO NOT EDIT
#include \"MINX/Game.h\"
#include \"MINX/GameTime.h\"
#include \"MINX/Input/Keyboard.h\"
#ifndef ${fileName^^}_H_
#define ${fileName^^}_H_

using namespace MINX;

namespace MINX_${fileName^^}
{
	class $fileName : public Game
	{
		public:
			$fileName();
			void Initialize();
			void LoadContent();
			void UnloadContent();
			void Update(GameTime * gameTime);
			void Draw(GameTime * gameTime);
	};
}

#endif" > "$projectDir/src/$fileName.h"

echo "
#include \"$fileName.h\"

using namespace MINX_${fileName^^};


$fileName::$fileName() : Game::Game()
{
	//This is the constructor. Put stuff here that should happen when the Game is created.

	isRunning = true;
	Game::SetVideoOptions(640, 480, \"$fileName\");
}

void $fileName::Initialize()
{
	//Put stuff here that should happen when the Game is initialized.
	Game::Initialize();
}

void $fileName::LoadContent()
{
	//Put stuff here that loads content for your game.
	Game::LoadContent();
}

void $fileName::UnloadContent()
{
	//Put stuff here that unloads content from your game.
	Game::UnloadContent();
}

void $fileName::Update(GameTime * gameTime)
{
	//Put stuff here to update the logic in your game each tick.
	Game::Update(gameTime);
}

void $fileName::Draw(GameTime * gameTime)
{
	gameWindow->Clear();

	//Put stuff here to draw your game each frame.
	Game::Draw(gameTime);
}" > "$projectDir/src/$fileName.cpp"

echo "
//AUTOGENERATED FILE: DO NOT EDIT
#include \"$fileName.h\"
using namespace MINX_${fileName^^};
int main(int argc, char ** argv)
{
	$fileName * game = new $fileName();
	game->Run();
	exit(0);
}" > "$projectDir/src/Program.cpp"


echo "INCDIR = -I/usr/include/freetype2 -I/usr/include/MINX
CPPFLAGS += -g -Wall -W \$(INCDIR) -std=c++11
LFLAGS = -lMINX -lGL -lfreetype -lglfw -lX11 -lXxf86vm -lpthread -lXrandr -lXi -lvlc
CXX = g++
SOURCES = \$(wildcard ./src/*.cpp)
OBJECTS = \$(patsubst ./src/%.cpp,./src/%.o,\$(wildcard ./src/*.cpp))
TARGET = $fileName

all: \$(OBJECTS)
	test -d \"./bin/\" || mkdir -p \"./bin/\"
	\$(CXX) \$(CPPFLAGS) \$(OBJECTS) \$(LFLAGS) -o ./bin/\$(TARGET)" > "$projectDir/makefile"
