#pragma once

#include "pch.h"
#include "cli.h"
#include "color.h"
#include "iocolor.h"

namespace cli
{
	template<typename CHAR_T = uint8_t>
	class CLI_API ColoredChar
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

	//private:
		Color color;

		CHAR_T character = ' ';
	};
}

inline std::ostream & operator<<(std::iostream & os, const cli::ColoredChar<uint8_t> & cc)
{
	os << cc.color << cc.character;

	return os;
}