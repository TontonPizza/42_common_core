#include <string>
#include <iostream>


int main()
{
	std::string		message = "HI THIS IS BRAIN";
	std::string&	msgRef  = message;
	std::string*	msgPtr	= &message;

//	std::cout << "message : " << message << std::endl;
	std::cout << "ref     : " << msgRef  << std::endl;
	std::cout << "ptr     : " << *msgPtr << std::endl;
}