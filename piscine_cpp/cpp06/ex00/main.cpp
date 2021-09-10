#include "convert.hpp"



int main(int argc, char **argv)
{
	t_data data;;
	data.input = argv[argc - 1];
	data.flag = -1;
	data.value = atof((data.input).c_str());
	data.flag = is_valid(data.input);
	if (data.flag == character)
		data.value = static_cast<double>(data.input.at(0));

	display_values(&data);
}