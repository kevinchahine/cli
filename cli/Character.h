#pragma once

#include "pch.h"
#include "cli.h"
#include "color.h"
#include "line_char.h"
#include "block_char.h"

#include <boost/variant.hpp>	// Break this down into only the headers that we need

#include <iostream>

namespace cli
{
	class CLI_API Character
	{
	public:

		Character & operator=(uint8_t ch);
		Character & operator=(const lines::line_char & lineChar);
		Character & operator=(const blocks::block_char & blockChar);
		
		// ex:
		//	Character a = cli::line_char::horizontal;
		//	Character b = cli::line_char::vertical;
		//	Character c = a + b;
		Character operator+(uint8_t ch) const;
		Character operator+(const lines::line_char & lineChar) const;
		Character operator+(const blocks::block_char & blockChar) const;
		
		Character & operator+=(uint8_t ch);
		Character & operator+=(const lines::line_char & lineChar);
		Character & operator+=(const blocks::block_char & blockChar);

		Character operator-(uint8_t ch) const;
		Character operator-(const lines::line_char & lineChar) const;
		Character operator-(const blocks::block_char & blockChar) const;

		CLI_API friend std::ostream & operator<<(std::ostream & os, const cli::Character & rhs);

	protected:
		boost::variant<uint8_t, lines::line_char, blocks::block_char> m_value;
	};

	CLI_API std::ostream & operator<<(std::ostream & os, const cli::Character & rhs);
}

