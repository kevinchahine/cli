#pragma once

#include "pch.h"
#include "cli.h"

#include <iostream>

namespace cli
{
	namespace blocks {
		// Externs
		extern const unsigned char BLOCK_CHARS[];

		class block_char
		{
		public:
			block_char() = default;
			block_char(uint8_t value) : m_value(value) {}
			block_char(const block_char &) = default;
			block_char(block_char &&) noexcept = default;
			virtual ~block_char() noexcept = default;
			block_char & operator=(const block_char &) = default;
			block_char & operator=(block_char &&) noexcept = default;

			friend std::ostream & operator<<(std::ostream & os, const block_char & lhs) {
				os << BLOCK_CHARS[lhs.m_value];

				return os;
			}

			bool isValid() const { return m_value >= 0 && m_value <=5; }
			bool isInValid() const { return !isValid(); }

			//uint8_t & value() { return m_value; }
			const uint8_t & value() const { return m_value; }

			template<typename T>
			T as() const {
				return static_cast<T>(m_value);
			}

		protected:

			// Limits:
			//	0 - Empty
			//	1 - Top
			//	2 - Bottom
			//	3 - Left
			//	4 - Right
			//	5 - Full
			uint8_t m_value;
		};

		// --- pre-defined constants ---
		const block_char empty(0);
		const block_char top(1);
		const block_char bottom(2);
		const block_char left(3);
		const block_char right(4);
		const block_char full(5);
	}
}
