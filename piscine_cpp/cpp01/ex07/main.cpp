#include <iostream>
#include <string>
#include <fstream>

std::string		replace_in_line(std::string & line, std::string & old_str, std::string & new_str)
{
	size_t 			pos;

	pos = line.find(old_str);
	while (pos != std::string::npos)
	{
		line.replace(pos, old_str.length(), new_str);
		pos = line.find(old_str, pos + new_str.length());
	}
	return (line);
}

void search_and_edit(std::string & filename, std::string & str_old, std::string & str_new)
{
	std::ifstream source;
	std::ofstream destination;
	source.open(filename.c_str());
	if (!source.is_open())
	{
		std::cout << "error opening files" << std::endl;
		return ;
	}
	destination.open((filename + ".replace").c_str());
	if (!destination.is_open())
	{
		std::cout << "error opening files" << std::endl;
		return ;
	}
	std::string line;
	while (getline(source, line))
	{
		destination << replace_in_line(line, str_old, str_new) << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "incorrect usage" << std::endl;
		return 0;
	}

	std::string filename(argv[1]);
	std::string str_old(argv[2]);
	std::string str_new(argv[3]);

	if (str_old.length() == 0 | str_new.length() == 0)
	{
		std::cout << "bad arguments" << std::endl;
		return 0;
	}

	search_and_edit(filename, str_old, str_new);
}