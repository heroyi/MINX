#    MINX - A C++ Graphics and Input Wrapper Library
#    Copyright (C) 2013  MINX Team
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
echo "Please type the directory in which you would like to create the new MINX project: "

read projectDir

test -d "$projectDir" || mkdir -p "$projectDir" && cp template.h "$projectDir"