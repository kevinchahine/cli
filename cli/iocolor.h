#pragma once

#include "pch.h"
#include "cli.h"
#include "color.h"

#include <iostream>
#include <stack>

//#ifdef WIN32
#include <Windows.h>
//#else
// ... Something for linux
//#endif

namespace cli
{
	
	static WORD currColor = Color::calcColor(Color::WHITE, Color::BLACK);
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	static CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	static std::stack<std::ios_base::fmtflags> flags;
	static std::stack<WORD> colorStack;

	// Stream Manipulator class
	// Purpose: Sets color of the next characters printed to console
	// Ex: 
	//		using namespace cli;
	//		
	//		cout << setcolor(color::GREEN) << "Hello";
	class setcolor
	{
	public:
		setcolor(WORD color) :
			newColor(color) {}

		setcolor(Color::type foreground, Color::type background) :
			newColor(Color::calcColor(foreground, background)) {}

		friend std::ostream& operator<<(std::ostream& os, const setcolor& rhs)
		{
			if (currColor != rhs.newColor) {
				SetConsoleTextAttribute(h, rhs.newColor);
				currColor = rhs.newColor;
			}

			return os;
		}

	protected:
		WORD newColor;
	};

	// Stream Manipulator class
	// Purpose: Sets color of the next characters printed to console
	class setfg : public setcolor
	{
	public:
		setfg(Color::type fgColor) : 
			setcolor(fgColor, Color::calcBackground(static_cast<Color::type>(currColor))) {}
	};

	class setbg : public setcolor
	{
	public:
		setbg(Color::type bgColor) : 
			setcolor(Color::calcForeground(static_cast<Color::type>(currColor)), bgColor) {}
	};

	class push
	{
	public:

		friend std::ostream& operator<<(std::ostream& os, const push& push)
		{
			flags.push(os.flags());
			colorStack.push(currColor);
			return os;
		}
	};

	class pop
	{
	public:

		friend std::ostream& operator<<(std::ostream& os, const pop& pop)
		{
			os << setcolor(colorStack.top());
			colorStack.pop();
			os.flags(flags.top());
			flags.pop();
			return os;
		}
	};

} // namespace cli

CLI_API std::ostream& operator<<(std::ostream& os, const cli::Color& rhs);
