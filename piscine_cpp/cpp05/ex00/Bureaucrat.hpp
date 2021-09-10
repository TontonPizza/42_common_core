#ifndef CPP05_BUREAUCRAT_HPP
#define CPP05_BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ostream>

class Bureaucrat {
public:
							Bureaucrat(const std::string & name, int grade);
							Bureaucrat(const Bureaucrat & T);
							~Bureaucrat();
							Bureaucrat &operator=(const Bureaucrat & T);

	void 					incrementGrade(int val);
	void 					decrementGrade(int val);

	int 					getGrade() const;
	const std::string & 	getName() const;

private:

	const std::string	name;
	int					grade;
	Bureaucrat();

	void 				checkValue(int val);

	class GradeTooHighException: public std::exception
	{
	public :
		virtual const char * what() const throw() { return ("grade too high"); }
	};

	class GradeTooLowException: public std::exception
	{
	public :
		virtual const char *what() const throw() { return ("grade too low"); }
	};
};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & T);

#endif //CPP05_BUREAUCRAT_HPP
