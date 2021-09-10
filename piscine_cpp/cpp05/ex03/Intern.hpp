#ifndef CPP05_INTERN_HPP
#define CPP05_INTERN_HPP

#include <string.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
				Intern();
				Intern(Intern & T);
				~Intern();
				Intern &operator=(const Intern & T);

	Form *		makeForm(std::string identifier, std::string target);

	Form *		makePardonForm(std::string & target);
	Form *		makeRequestForm(std::string & target);
	Form *		makeCreationForm(std::string & target);
private:

	int 			scoreInput(std::string input);
	void 			initFormWriter();
	Form *(Intern::*formWriters[3])(std::string & target);

	class IdentifierException : public std::exception
	{
	public:
		virtual const char * what() const throw() {return ("invalid identifier"); }
	};

};


#endif //CPP05_INTERN_HPP
