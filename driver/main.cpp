#include <cli/iocolor.h>
#include <cli/color.h>
#include <cli/colored_char.h>
#include <cli/Matrix.h>
#include <cli/Character.h>

#include <iostream>
#include <string>

#include <boost/variant.hpp>

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

	//cli::Matrix<cli::ColoredChar<uint8_t>> m;
	//cli::Matrix m;
	//m.print();

	cli::Character ch;
	ch = 'j';

	cout << ch << '\n';

	ch = ch + cli::lines::cross;

	cout << ch << '\n';

	cin.get();
	return 0;
}