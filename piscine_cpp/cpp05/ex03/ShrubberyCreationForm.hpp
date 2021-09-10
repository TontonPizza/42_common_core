#ifndef CPP05_SHRUBBERYCREATIONFORM_HPP
#define CPP05_SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Form.hpp"

class ShrubberyCreationForm: public virtual Form {
public:
							ShrubberyCreationForm (const std::string & target);
							ShrubberyCreationForm (const ShrubberyCreationForm  & T);
							virtual ~ShrubberyCreationForm ();
	ShrubberyCreationForm &	operator=(const ShrubberyCreationForm  & T);
	void					execute(Bureaucrat const & executor) const;
	virtual void			doNothing();
private:
	std::string 			target;
							ShrubberyCreationForm ();

	class OpeningFileException: public std::exception{
	private:
		virtual const char *what() const throw() { return ("Error with file"); };
	};

};


#endif //CPP05_SHRUBBERYCREATIONFORM_HPP
