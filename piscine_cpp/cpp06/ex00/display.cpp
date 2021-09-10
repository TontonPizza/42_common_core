#include "convert.hpp"

std::string		add_dot(double value)
{
	if (abs(value) >= 1000000)
		return "";
	if (value == floor(value))
		return ".0";
	return "";
}


void 	display_double(t_data *data)
{
	if (data->flag == -1)
		std::cout << "double : impossible" << std::endl;
	else
		std::cout << "double : " << data->value << add_dot(data->value) << std::endl;
}

void 	display_float(t_data *data)
{
	if (data->flag == -1)
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(data->value) << add_dot(data->value) << "f" << std::endl;
}

void 	display_int(t_data *data)
{
	if (data->flag != number && data->flag != character)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(data->value) << std::endl;
}

void 	display_char(t_data *data)
{
	if (data->value > 127 || data->value < 20)
		std::cout << "char : Non displayable" << std::endl;
	else if (data->flag == literal)
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(data->value) << "'"<< std::endl;
}

void 	display_values(t_data *data)
{
	display_char(data);
	display_int(data);
	display_float(data);
	display_double(data);
}