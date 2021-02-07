#pragma once

#include "cli.h"

#include <iostream>

namespace cli
{
	class CLI_API Color {
	public:
		// Alias the data used to store color values
		using type = uint8_t;

		static const type BLACK = 0;
		static const type BLUE = 1;
		static const type GREEN = 2;
		static const type CYAN = 3;
		static const type RED = 4;
		static const type MAGENTA = 5;
		static const type YELLOW = 6;
		static const type LIGHTGRAY = 7;
		static const type GRAY = 8;
		static const type LIGHTBLUE = 9;
		static const type LIGHTGREEN = 10;
		static const type LIGHTCYAN = 11;
		static const type LIGHTRED = 12;
		static const type LIGHTMAGENTA = 13;
		static const type BROWN = 14;
		static const type WHITE = 15;

		// --- Constructors and Operator Overloads ---
		Color(type hue = WHITE) : hue(hue) {}
		Color(const Color &) = default;
		Color(Color &&) noexcept = default;
		virtual ~Color() noexcept = default;
		Color & operator=(const Color &) = default;
		Color & operator=(Color &&) noexcept = default;

		// --- static helper methods ---

		static type calcColor(type foreground, type background)
		{
			return ((foreground & 0b0000'1111) | (background << 4));
		}

		static type calcForeground(type color)
		{
			return (color & 0b0000'1111);
		}

		static type calcBackground(type color)
		{
			return (color >> 4);
		}

		void setfg(type hue);
		void setbg(type hue);
		void setcolor(type hue);

		type getfg() const;
		type getbg() const;
		type getcolor() const;

	protected:
		// Stores shade of color
		type hue;
	};	// class color

	extern CLI_API const Color black;
	extern CLI_API const Color blue;
	extern CLI_API const Color green;
	extern CLI_API const Color cyan;
	extern CLI_API const Color red;
	extern CLI_API const Color magenta;
	extern CLI_API const Color yellow;
	extern CLI_API const Color lightgray;
	extern CLI_API const Color gray;
	extern CLI_API const Color lightblue;
	extern CLI_API const Color lightgreen;
	extern CLI_API const Color lightcyan;
	extern CLI_API const Color lightred;
	extern CLI_API const Color lightmagenta;
	extern CLI_API const Color brown;
	extern CLI_API const Color white;
}