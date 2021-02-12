#include <cli/iocolor.h>
#include <cli/color.h>
#include <cli/ColoredChar.h>
#include <cli/Matrix.h>
#include <cli/Character.h>
#include <cli/DrawFunctions.h>
#include <cli/CheckerBoard.h>

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
		<< cli::color::red << "===============\n"
		<< cli::color::green << "=== CLI LIB ===\n"
		<< cli::color::blue << "===============\n";

	cli::color::Color c(cli::color::Color::BROWN);

	cout << cli::color::setfg(cli::color::Color::BLUE) << '='
		<< cli::color::setcolor(c.getcolor()) << '='
		<< cli::color::cyan << '='
		<< cli::color::black << '='
		<< cli::color::blue << '='
		<< cli::color::green << '='
		<< cli::color::cyan << '='
		<< cli::color::red << '='
		<< cli::color::magenta << '='
		<< cli::color::yellow << '='
		<< cli::color::lightgray << '='
		<< cli::color::gray << '='
		<< cli::color::lightblue << '='
		<< cli::color::lightgreen << '='
		<< cli::color::lightcyan << '='
		<< cli::color::lightred << '='
		<< cli::color::lightmagenta << '='
		<< cli::color::brown << '='
		<< cli::color::white << '='
		<< '\n';

	cli::boards::CheckerBoard board;
	board.drawBackground();

	board.placePiece('R', 0, 0, false);
	board.placePiece('N', 0, 1, false);
	board.placePiece('B', 0, 2, false);
	board.placePiece('K', 0, 3, false);
	board.placePiece('Q', 0, 4, false);
	board.placePiece('B', 0, 5, false);
	board.placePiece('N', 0, 6, false);
	board.placePiece('R', 0, 7, false);
	board.placePiece('p', 1, 0, false);
	board.placePiece('p', 1, 1, false);
	board.placePiece('p', 1, 2, false);
	board.placePiece('p', 1, 3, false);
	board.placePiece('p', 1, 4, false);
	board.placePiece('p', 1, 5, false);
	board.placePiece('p', 1, 6, false);
	board.placePiece('p', 1, 7, false);

	board.placePiece('R', 7, 0, true);
	board.placePiece('N', 7, 1, true);
	board.placePiece('B', 7, 2, true);
	board.placePiece('K', 7, 3, true);
	board.placePiece('Q', 7, 4, true);
	board.placePiece('B', 7, 5, true);
	board.placePiece('N', 7, 6, true);
	board.placePiece('R', 7, 7, true);
	board.placePiece('p', 6, 0, true);
	board.placePiece('p', 6, 1, true);
	board.placePiece('p', 6, 2, true);
	board.placePiece('p', 6, 3, true);
	board.placePiece('p', 6, 4, true);
	board.placePiece('p', 6, 5, true);
	board.placePiece('p', 6, 6, true);
	board.placePiece('p', 6, 7, true);
	
	board.highlight(4, 5);
	board.highlight(4, 4);
	board.highlight(5, 4);
	board.highlight(0, 0);
	board.highlight(7, 7);

	board.print();
	
	//cli::color::printAllColors();

	this_thread::sleep_for(chrono::seconds(2));
	//cin.get();
	return 0;
}