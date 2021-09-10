#include "header.hpp"




int main()
{
	srand((static_cast<unsigned>(time(NULL))));

	std::cout << "test from pointer :" << std::endl;
	int i = 0;
	while (i++ < 10)
		test_pointer();
	std::cout << std::endl;

	std::cout << "test from reference :" << std::endl;
	i = 0;
	while (i++ < 10)
		test_reference();
	std::cout << std::endl;
}



void	test_pointer()
{
	Base * b = generate_pointer();
	identify_from_pointer(b);
	delete b;
	std::cout << " ";
}

void 	test_reference()
{
	Base * b = generate_pointer();
	identify_from_reference(*b);
	std::cout << " ";
}



Base * generate_pointer(void)
{
	int id = rand() % 3;
	std::cout << static_cast<char>(id + 'a') << "->";
	switch (id)
	{
		case 0 : return dynamic_cast<Base *>(new A);
		case 1 : return dynamic_cast<Base *>(new B);
		case 2 : return dynamic_cast<Base *>(new C);
		default: return NULL;
	}
}


void identify_from_pointer(Base * p)
{
	A * a = dynamic_cast<A*>(p);
	if (a != 0)
		std::cout << "A";
	B * b = dynamic_cast<B*>(p);
	if (b != 0)
		std::cout << "B";
	C * c = dynamic_cast<C*>(p);
	if (c != 0)
		std::cout << "C";
}

void identify_from_reference(Base & p)
{
	try {
		A & a = dynamic_cast<A&>(p);
		(void)(a);
		std::cout << "A";
	}
	catch (std::bad_cast &bc){
	}
	try {
		B & b = dynamic_cast<B&>(p);
		(void)(b);
		std::cout << "B";
	}
	catch (std::bad_cast &bc){
	}
	try {
		C & c = dynamic_cast<C&>(p);
		(void)(c);
		std::cout << "C";
	}
	catch (std::bad_cast &bc){
	}
}





