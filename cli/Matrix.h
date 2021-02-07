#pragma once

#include "pch.h"
#include "cli.h"
#include "color.h"
#include "iocolor.h"
#include "colored_char.h"

#include <boost/multi_array.hpp>	// Break this down into only the headers we need

#include <iostream>
#include <iomanip>

using COLORED_CHAR_T = cli::ColoredChar<uint8_t>;
namespace cli
{
	//template<typename COLORED_CHAR_T>
	class CLI_API Matrix 
	{
	public:

		void print(std::ostream & os = std::cout, size_t nTabs = 0) const 
		{
			const size_t N_ROWS = ccMatrix.shape()[0];
			const size_t N_COLS = ccMatrix.shape()[1];

			os << cli::push();

			for (size_t row = 0; row < N_ROWS; row++) {
				os << std::setfill(' ') << std::setw(nTabs * 4) << '\0';	// print tabs left of matrix

				for (size_t col = 0; col < N_COLS; col++) {
					os << ccMatrix[row][col].color << ccMatrix[row][col].character;
				}

				os << '\n';
			}
			os << cli::pop() << '\n';
		}

	protected:
		using cc_matrix_t = boost::multi_array<COLORED_CHAR_T, 2>;

		cc_matrix_t ccMatrix;
	};

	//template<typename COLORED_CHAR_T>
	//void Matrix/*<COLORED_CHAR_T>*/::print(std::ostream & os, size_t nTabs) const
	//{
	//	const size_t N_ROWS = ccMatrix.shape()[0];
	//	const size_t N_COLS = ccMatrix.shape()[1];
	//
	//	os << cli::push();
	//
	//	for (size_t row = 0; row < N_ROWS; row++) {
	//		os << std::setfill(' ') << std::setw(nTabs * 4) << '\0';	// print tabs left of matrix
	//
	//		for (size_t col = 0; col < N_COLS; col++) {
	//			os << ccMatrix[row][col].color << ccMatrix[row][col].character;
	//		}
	//
	//		os << '\n';
	//	}
	//	os << cli::pop() << '\n';
	//}
}
