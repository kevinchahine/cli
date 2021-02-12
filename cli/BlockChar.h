#pragma once

#include "pch.h"
#include "cli.h"

#include <iostream>

namespace cli
{
	namespace blocks {
		// Externs
		extern const unsigned char BLOCK_CHARS[];

		class CLI_API BlockChar
		{
		public:
			BlockChar() = default;
			BlockChar(uint8_t value) : m_value(value) {}
			BlockChar(const BlockChar &) = default;
			BlockChar(BlockChar &&) noexcept = default;
			virtual ~BlockChar() noexcept = default;
			BlockChar & operator=(const BlockChar &) = default;
			BlockChar & operator=(BlockChar &&) noexcept = default;

			friend std::ostream & operator<<(std::ostream & os, const BlockChar & lhs) {
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
		const BlockChar empty(0);
		const BlockChar top(1);
		const BlockChar bottom(2);
		const BlockChar left(3);
		const BlockChar right(4);
		const BlockChar full(5);
	}
}
