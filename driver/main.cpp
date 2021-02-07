#include <cli/iocolor.h>
#include <cli/color.h>
#include <cli/colored_char.h>
#include <cli/Matrix.h>
#include <cli/Character.h>

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <array>

#include <boost/variant.hpp>
#include <boost/multi_array.hpp>

using namespace std;

int main()
{
	cout
		<< "===============\n"
		<< "=== CLI LIB ===\n"
		<< "===============\n";

	cli::Color c(cli::Color::BROWN);

	cout << cli::setfg(cli::Color::BLUE) << '='
		<< cli::setcolor(c.getcolor()) << '='
		<< cli::cyan << '='
		<< cli::black << '='
		<< cli::blue << '='
		<< cli::green << '='
		<< cli::cyan << '='
		<< cli::red << '='
		<< cli::magenta << '='
		<< cli::yellow << '='
		<< cli::lightgray << '='
		<< cli::gray << '='
		<< cli::lightblue << '='
		<< cli::lightgreen << '='
		<< cli::lightcyan << '='
		<< cli::lightred << '='
		<< cli::lightmagenta << '='
		<< cli::brown << '='
		<< cli::white << '='
		<< '\n';

	cli::Matrix m;// <cli::ColoredChar<uint8_t>> m;
	cli::Matrix::extent_gen extents;
	m.resize(extents[20][40]);

	const size_t N_ROWS = m.shape()[0];
	const size_t N_COLS = m.shape()[1];

	for (size_t r = 0; r < N_ROWS; r++) {
		m[r][0].character = cli::lines::vertical;
		m[r][N_COLS - 1].character = cli::lines::vertical;
	}

	for (size_t c = 0; c < N_COLS; c++) {
		m[0][c].character = cli::lines::horizontal;
		m[N_ROWS - 1][c].character = cli::lines::horizontal;
	}

	m[0][0] = cli::lines::down + cli::lines::right;
	m[0][N_COLS - 1] = cli::lines::down + cli::lines::left;
	m[N_ROWS - 1][0] = cli::lines::up + cli::lines::right;
	m[N_ROWS - 1][N_COLS - 1] = cli::lines::up + cli::lines::left;

	m.print();

	this_thread::sleep_for(chrono::seconds(2));
	//cin.get();
	return 0;
}