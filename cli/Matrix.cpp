#include "pch.h"
#include "Matrix.h"

using namespace std;

void cli::Matrix::print(std::ostream & os, size_t nTabs) const
{
	const size_t N_ROWS = this->shape()[0];
	const size_t N_COLS = this->shape()[1];
	
	os << cli::push();

	for (size_t row = 0; row < N_ROWS; row++) {
		os << std::setfill(' ') << std::setw(nTabs * 4) << '\0';	// print tabs left of matrix
	
		for (size_t col = 0; col < N_COLS; col++) {
			os << (*this)[row][col];
		}
	
		os << '\n';
	}
	os << cli::pop() << '\n';
}
