#pragma once

#include "pch.h"
#include "cli.h"

#include <iostream>
#include <bitset>
#include <iterator>

namespace cli
{
	namespace lines {
		// Externs
		CLI_API extern const unsigned char LINES[];

		class line_char
		{
		public:
			line_char() = default;
			line_char(uint8_t value) : m_value(value) {}
			line_char(const line_char &) = default;
			line_char(line_char &&) noexcept = default;
			virtual ~line_char() noexcept = default;
			line_char & operator=(const line_char &) = default;
			line_char & operator=(line_char &&) noexcept = default;

			// Adds a line component to the character
			// ex: 
			// using namespace utf;
			// line_char l;
			// l = lines::right + lines::left;
			// cout << l;		// prints horizontal line
			line_char operator+(const line_char & other) const {
				return this->m_value | other.m_value;
			}

			// Adds a line component to the character
			// ex: 
			// using namespace utf;
			// line_char l = lines::right;
			// l += lines::left;
			// cout << l;		// prints horizontal line
			line_char operator+=(const line_char & other) {
				this->m_value = this->m_value | other.m_value;
				return this->m_value;
			}

			// Removes a line component from the character
			// ex: 
			// using namespace utf;
			// line_char l = lines::cross - lines::up;
			// cout << l;		// prints T-shaped line
			line_char operator-(const line_char & other) const {
				return this->m_value & ~other.m_value;
			}

			// Removes a line component from the character
			// ex: 
			// using namespace utf;
			// line_char l = lines::cross;
			// l -= lines::up;
			// cout << l;		// prints T-shaped line
			line_char operator-=(const line_char & other) {
				this->m_value = this->m_value & ~other.m_value;
				return this->m_value;
			}

			friend std::ostream & operator<<(std::ostream & os, const line_char & lhs) {
				os << LINES[lhs.m_value];

				return os;
			}

			bool isValid() const { return LINES[m_value] != '#'; }
			bool isInValid() const { return !isValid(); }

			// Returns bitwise value of line_char. 
			// Not the displayable character itself.
			uint8_t & value() { return m_value; }
			const uint8_t & value() const { return m_value; }

			template<typename T>
			T as() const {
				return static_cast<T>(m_value);
			}

		protected:
			// Bitwise value indicating direction of each line
			// To be used as index to LINES[] array to get cooresponding unicode line character
			// 
			// Does not equal value of the cooresponding character
			// 
			// Ex: 
			//	uint8_t m_value = 0b0000'0011;		// 3 - left, right (horizontal line)
			//	cout << m_value;					// No - does not print horizontal line
			//	cout << utf::LINES[m_value];		// Yes - prints horizontal line char
			// 
			// 0 (LSB)	RIGHT
			// 1		LEFT
			// 2		DOWN
			// 3		UP
			// 4		ANOTHER RIGHT
			// 5		ANOTHER LEFT
			// 6		ANOTHER DOWN
			// 7 (MSB)	ANOTHER UP
			uint8_t m_value = 0b0000'0000;
		};

		// --- pre-defined constants ---
		const line_char up(0b0000'1000);
		const line_char double_up(0b1000'1000);
		const line_char down(0b0000'0100);
		const line_char double_down(0b0100'0100);
		const line_char left(0b0000'0010);
		const line_char double_left(0b0010'0010);
		const line_char right(0b0000'0001);
		const line_char double_right(0b0001'0001);
		const line_char horizontal(0b0000'0011);
		const line_char double_horizontal(0b0011'0011);
		const line_char vertical(0b0000'1100);
		const line_char double_vertical(0b1100'1100);
		const line_char cross(0b0000'1111);
		const line_char double_cross(0b1111'1111);
	}
}