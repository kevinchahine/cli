#include "pch.h"
#include "Character.h"

namespace cli
{
	// ========================================================================

	Character & Character::operator=(uint8_t ch)
	{
		m_value = ch;
	
		return *this;
	}
	
	Character & Character::operator=(const lines::line_char & lineChar)
	{
		m_value = lineChar;
	
		return *this;
	}
	
	Character & Character::operator=(const blocks::block_char & blockChar)
	{
		m_value = blockChar;
	
		return *this;
	}

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	Character Character::operator+(uint8_t ch) const
	{
		Character ret;
	
		if (const uint8_t * val = boost::get<uint8_t>(&m_value)) {
			ret = *val + ch;
		}
		else {
			ret = ch;
		}
	
		return ret;
	}
	
	Character Character::operator+(const lines::line_char & lineChar) const
	{
		Character ret;

		if (const lines::line_char * val = boost::get<lines::line_char>(&m_value)) {
			ret = *val + lineChar;
		}
		else {
			ret = lineChar;
		}

		return ret;
	}
	
	Character Character::operator+(const blocks::block_char & blockChar) const
	{
		Character ret;

		if (const blocks::block_char * val = boost::get<blocks::block_char>(&m_value)) {
			ret = blockChar;
		}
		else {
			ret = blockChar;
		}

		return ret;
	}

	Character & Character::operator+=(uint8_t ch)
	{
		if (uint8_t * val = boost::get<uint8_t>(&m_value)) {
			*val += ch;
		}
		else {
			*val = ch;
		}

		return *this;
	}

	Character & Character::operator+=(const lines::line_char & lineChar)
	{
		if (lines::line_char * val = boost::get<lines::line_char>(&m_value)) {
			*val += lineChar;
		}
		else {
			*val = lineChar;
		}

		return *this;
	}

	Character & Character::operator+=(const blocks::block_char & blockChar)
	{
		if (blocks::block_char * val = boost::get<blocks::block_char>(&m_value)) {
			*val = blockChar;
		}
		else {
			*val = blockChar;
		}

		return *this;
	}

	// ------------------------------------------------------------------------

	Character Character::operator-(uint8_t ch) const
	{
		Character ret;

		if (const uint8_t * val = boost::get<uint8_t>(&m_value)) {
			ret = *val - ch;
		}
		else {
			ret = ch;
		}

		return ret;
	}
	
	Character Character::operator-(const lines::line_char & lineChar) const
	{
		Character ret;

		if (const lines::line_char * val = boost::get<lines::line_char>(&m_value)) {
			ret = *val - lineChar;
		}
		else {
			ret = lineChar;
		}

		return ret;
	}
	
	Character Character::operator-(const blocks::block_char & blockChar) const
	{
		Character ret;

		if (const blocks::block_char * val = boost::get<blocks::block_char>(&m_value)) {
			ret = blockChar;
		}
		else {
			ret = blockChar;
		}

		return ret;
	}

	// << << << << << << << << << << << << << << << << << << << << << << << << 
	std::ostream & operator<<(std::ostream & os, const cli::Character & rhs)
	{
		os << rhs.m_value;

		return os;
	}
}
