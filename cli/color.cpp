#include "pch.h"
#include "color.h"

namespace cli
{
	CLI_API const Color black(Color::BLACK);
	CLI_API const Color blue(Color::BLUE);
	CLI_API const Color green(Color::GREEN);
	CLI_API const Color cyan(Color::CYAN);
	CLI_API const Color red(Color::RED);
	CLI_API const Color magenta(Color::MAGENTA);
	CLI_API const Color yellow(Color::YELLOW);
	CLI_API const Color lightgray(Color::LIGHTGRAY);
	CLI_API const Color gray(Color::GRAY);
	CLI_API const Color lightblue(Color::LIGHTBLUE);
	CLI_API const Color lightgreen(Color::LIGHTGREEN);
	CLI_API const Color lightcyan(Color::LIGHTCYAN);
	CLI_API const Color lightred(Color::LIGHTRED);
	CLI_API const Color lightmagenta(Color::LIGHTMAGENTA);
	CLI_API const Color brown(Color::BROWN);
	CLI_API const Color white(Color::WHITE);

	void Color::setfg(type hue)
	{
		type bg = calcBackground(this->hue);

		this->hue = calcColor(hue, bg);
	}

	void Color::setbg(type hue)
	{
		type fg = calcForeground(this->hue);

		this->hue = calcColor(fg, hue);
	}

	void Color::setcolor(type hue)
	{
		this->hue = hue;
	}

	Color::type Color::getfg() const
	{
		return calcForeground(this->hue);
	}

	Color::type Color::getbg() const
	{
		return calcBackground(this->hue);
	}

	Color::type Color::getcolor() const
	{
		return this->hue;
	}

} // namespace cli