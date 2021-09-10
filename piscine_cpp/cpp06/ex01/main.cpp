#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

typedef struct	s_data
{
	std::string *	str_1;
	int				num;
	std::string *	str_2;
}				Data;

std::string  * random_string()
{
	std::string * result = new std::string("XYZ");
	if (getpid() % (rand() % 2 + 1) == 0)
	{
		delete result;
		result = new std::string("ABC");
	}
	return result;
}

int			random_int()
{
	return (getpid()%50);
}

void * serialize(void)
{
	Data * result = new Data ;

	result->str_1 = random_string();
	result->num	= random_int();
	result->str_2 = random_string();

	return reinterpret_cast<void *>(result);
}

Data * deserialize(void * raw)
{
	Data * result = reinterpret_cast<Data *>(raw);
	return result;
}

int main()
{
	void * raw_data = serialize();

	std::cout << "raw data : " << raw_data << std::endl;

	Data * data = deserialize(raw_data);

	std::cout << "true data : " << data << std::endl;
	std::cout << *(data->str_1) << " " << std::endl;
	std::cout << data->num << std::endl;
	std::cout << *(data->str_2) << std::endl;

	delete	data->str_2;
	delete	data->str_1;
	delete  data;
}

