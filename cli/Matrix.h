#pragma once

#include "pch.h"
#include "cli.h"
#include "color.h"
#include "iocolor.h"
#include "colored_char.h"
#include "Character.h"

#include <boost/multi_array.hpp>	// Break this down into only the headers we need

#include <iostream>
#include <iomanip>

using COLORED_CHAR_T = cli::ColoredChar<cli::Character>;
using cc_matrix_t = boost::multi_array<COLORED_CHAR_T, 2>;

namespace cli
{
	//template<typename COLORED_CHAR_T>
	class CLI_API Matrix : public cc_matrix_t
	{
	public:

		void print(std::ostream & os = std::cout, size_t nTabs = 0) const;

	protected:
	};
} // namespace cli
