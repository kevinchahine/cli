#pragma once

#include "pch.h"
#include "cli.h"
#include "Character.h"
#include "Matrix.h"

#include <iostream>
#include <iomanip>

namespace cli
{
	// -------------------------------- DECLARATIONS --------------------------

	CLI_API void horizontalLine(Matrix & mat, const Point & p1, size_t width, const color::Color & color = color::white, bool doubleLines = false);

	CLI_API void verticalLine(Matrix & mat, const Point & p1, size_t height, const color::Color & color = color::white, bool doubleLines = false);

	CLI_API void rectangle(Matrix & mat, const Point & p1, const Point & p2, const color::Color & color = color::white, bool doubleLines = false);

	CLI_API void rectangle(Matrix & mat, const Point & origin, const Size & size, const color::Color & color = color::white, bool doubleLines = false);

}