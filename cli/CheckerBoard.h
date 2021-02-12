#pragma once

#include "pch.h"
#include "cli.h"
#include "color.h"
#include "Matrix.h"

namespace cli
{
	namespace boards
	{
		class CLI_API CheckerBoard : public Matrix
		{
		public:
			CheckerBoard();
			CheckerBoard(const CheckerBoard &) = default;
			CheckerBoard(CheckerBoard &&) noexcept = default;
			virtual ~CheckerBoard() noexcept = default;
			CheckerBoard & operator=(const CheckerBoard &) = default;
			CheckerBoard & operator=(CheckerBoard &&) noexcept = default;

			void setCellSize(const Size & cellSize);
			void setCellSize(int nRows, int nCols);

			// Removes any placed pieces.
			// Pieces need to be placed after calling this method
			// by calling .placePiece()
			void drawBackground();

			void placePiece(char piece, int row, int col, bool isWhite);

			void placePiece(char piece, const Point & pos, bool isWhite);

			void highlight(int row, int col);

			void highlight(const Point & pos);

			void print(std::ostream & os = std::cout, size_t nTabs = 0) const;

		protected:
			void drawBoarder();

			void drawCells();

			void drawRibbon();

		protected:
			color::Color darkCell = color::green;
			color::Color lightCell = color::brown;
			color::Color darkHighlight = color::red;
			color::Color lightHighlight = color::lightred;
			color::Color darkPiece = color::black;
			color::Color lightPiece = color::yellow;
			color::Color darkBoarder = color::green;
			color::Color lightBoarder = color::brown;

			Size cellSize{ 3, 5 };
		};
	}
}

