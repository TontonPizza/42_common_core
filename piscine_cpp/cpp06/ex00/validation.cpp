#include "convert.hpp"

bool one_dot_max(std::string input)
{
	int dot = 0;
	size_t i = 0;
	while (i < input.length())
	{
		if (input.at(i) == '.')
			dot++;
		i++;
	}
	if (dot > 1)
		return false;
	return true;
}

bool	has_one_char(std::string input)
{
	int char_count = 0;
	size_t i = 0;
	if (input.at(0) == '-' || input.at(0) == '+')
		i++;
	while (i < input.length() - 1)
	{
		if ((input.at(i) > '9' || input.at(i) < '0') && input.at(i) != '.')
			char_count++;
		i++;
	}
	if (char_count > 0)
		return false;
	return true;
}

bool 	last_char_is_valid(std::string input)
{
	const char c = input.at(input.length() - 1);
	if ((c < '0' || c > '9') && c != 'f')
		return false;
	return true;
}

bool	is_literal(std::string input)
{
	if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff")
		return true;
	if (input == "-inf" || input == "-inff" || input == "nan" || input == "nanf")
		return true;
	return false;
}

bool			is_char_literal(std::string input)
{
	if (input.length() != 1)
		return false;
	if (input.at(0) >= 21 && input.at(0) <= 127 && (input.at(0) > '9' || input.at(0) < '0'))
		return true;
	return false;
}

int 	is_valid(std::string input)
{
	if (is_literal(input))
		return literal;
	if (is_char_literal(input))
		return character;
	if (!last_char_is_valid(input))
		return -1;
	if (!one_dot_max(input))
		return -1;
	if (!has_one_char(input))
		return -1;
	return number;
}