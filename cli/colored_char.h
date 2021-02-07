#pragma once

#include "pch.h"
#include "cli.h"
#include "color.h"
#include "iocolor.h"

namespace cli
{
	template<typename CHAR_T = uint8_t>
	class ColoredChar
	{
	public:
		ColoredChar() = default;
		ColoredChar(const Color & color, CHAR_T character) :
			color(color),
			character(character) {}
		ColoredChar(const ColoredChar &) = default;
		ColoredChar(ColoredChar &&) noexcept = default;
		virtual ~ColoredChar() noexcept = default;
		ColoredChar & operator=(const ColoredChar &) = default;
		ColoredChar & operator=(ColoredChar &&) noexcept = default;

		ColoredChar & operator=(const CHAR_T & character) { this->character = character; return *this; }

		bool operator==(const ColoredChar & cc) const { return this->character == cc.character; }

		friend std::ostream & operator<<(std::ostream & os, const ColoredChar & cc) {
			os << cc.color << cc.character;

			return os;
		}

		Color color;

		CHAR_T character = ' ';
	};
}
