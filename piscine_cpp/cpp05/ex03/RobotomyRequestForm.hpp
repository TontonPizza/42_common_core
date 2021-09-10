#ifndef CPP05_ROBOTOMYREQUESTFORM_HPP
#define CPP05_ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm: public virtual Form {
public:
							RobotomyRequestForm (const std::string & target);
							RobotomyRequestForm (const RobotomyRequestForm  & T);
	virtual 				~RobotomyRequestForm ();
	RobotomyRequestForm &	operator=(const RobotomyRequestForm  & T);
	void					execute(Bureaucrat const & executor) const;
	virtual void			doNothing();

private:
	std::string 			target;
	RobotomyRequestForm ();

	class RobotomyException: public std::exception{
	private:
		virtual const char *what() const throw() { return ("can't robotomize"); };
	};

};


#endif //CPP05_RobotomyRequestForm_HPP
