#ifndef CPP05_PRESIDENTIALPARDONFORM_HPP
#define CPP05_PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Form.hpp"

class PresidentialPardonForm: public virtual Form {
public:
								PresidentialPardonForm (const std::string & target);
								PresidentialPardonForm (const PresidentialPardonForm  & T);
	virtual 					~PresidentialPardonForm ();
	PresidentialPardonForm &	operator=(const PresidentialPardonForm  & T);
	virtual void				execute(Bureaucrat const & executor) const;
	virtual void				doNothing();

private:
	std::string 				target;
								PresidentialPardonForm ();

	class PardonException: public std::exception{
	private:
		virtual const char *what() const throw() { return ("can't pardon"); };
	};

};


#endif //CPP05_PresidentialPardonForm_HPP
