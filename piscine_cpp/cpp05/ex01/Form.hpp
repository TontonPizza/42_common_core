#ifndef CPP05_FORM_HPP
#define CPP05_FORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
						Form(std::string name, int toSign, int toExec);
						Form(const Form & T);
						~Form();
						Form &operator=(const Form & T);

	std::string 		getName() const;
	int 				getSignGrade() const;
	int 				getExecGrade() const;
	bool 				getStatus() const;
	void 				setStatus(bool st);

	void 				beSigned(Bureaucrat & B);

private:
	const std::string 	name;
	const int 			gradeToSign;
	const int 			gradeToExecute;
	bool 				status;
	Form();

	class GradeTooHighException : public std::exception
		{
		public:
			virtual const char * what() const throw() { return ("grade too high"); }
		};
	class GradeTooLowException: public std::exception
		{
		public :
			virtual const char * what() const throw() { return ("grade too low"); }
	};

	void 				checkValue(int val);
};

std::ostream & operator<<(std::ostream & os, Form & T);

#endif //CPP05_FORM_HPP
