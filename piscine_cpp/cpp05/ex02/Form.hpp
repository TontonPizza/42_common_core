#ifndef CPP05_FORM_HPP
#define CPP05_FORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:
						Form(std::string name, int toSign, int toExec);
						Form(const Form & T);
						virtual ~Form();
						Form &operator=(const Form & T);

	virtual void		doNothing() = 0;
	std::string 		getName() const;
	int 				getSignGrade() const;
	int 				getExecGrade() const;
	bool 				getStatus() const;
	void 				setStatus(bool st);

	void 				beSigned(Bureaucrat & B);
	virtual void 		execute(Bureaucrat const & executor) const;

private:
						Form();
	const std::string 	name;
	const int 			gradeToSign;
	const int 			gradeToExecute;
	bool 				status;

	class NotSignedException	: public std::exception
		{
		public:
			virtual const char * what() const throw() { return ("form not signed"); }
		};

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
