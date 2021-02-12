#include "pch.h"
#include "framework.h"
#include "cli.h"
#include "iocolor.h"

namespace cli
{

} // namespace cli

CLI_API std::ostream & operator<<(std::ostream & os, const cli::color::Color & rhs)
{
	os << cli::color::setcolor(rhs.getcolor());

	return os;
}
