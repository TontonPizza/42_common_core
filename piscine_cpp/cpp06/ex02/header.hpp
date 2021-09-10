#include <string>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <typeinfo>
#include <iostream>

class Base
{
public:
	virtual ~Base() {};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

void 	identify_from_reference(Base & p);
void 	identify_from_pointer(Base * p);
Base * 	generate_pointer(void);
void 	test_reference();
void	test_pointer();