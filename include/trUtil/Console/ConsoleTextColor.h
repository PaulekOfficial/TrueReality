/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2017 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Maxim Serebrennik
*/
#pragma once

#include "Export.h"

namespace trUtil
{
	namespace Console
	{
		/**
		* Color Modes for the Console Window
		**/
		enum TR_UTIL_EXPORT TXT_COLOR
		{
			DEFAULT,
			BRIGHT_RED,
			RED,
			BRIGHT_GREEN,
			GREEN,
			BRIGHT_BLUE,
			BLUE,
			BRIGHT_YELLOW,
			YELLOW,
			WHITE,
			BRIGHT_CYAN,
			CYAN,
			BRIGHT_MAGENTA,
			MAGENTA,
			GRAY
		};

		/**
		* Changes Text color in the console window....
		**/
		void TR_UTIL_EXPORT ConsoleTextColor(TXT_COLOR TextColor);

        /**
        * Prints an example of all available colors
        * This is usually used for testing and development
        */
        void TR_UTIL_EXPORT PrintAllColors();
	}
}
