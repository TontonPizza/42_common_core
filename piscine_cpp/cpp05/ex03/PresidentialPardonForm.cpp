#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("presidential pardon", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target): Form("presidential pardon", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const  PresidentialPardonForm & T): Form(T.getName(), 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & T)
{
	this->Form::setStatus(T.getStatus());
	this->target = T.target;
	return (*this);
}


void 					PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->Form::execute(executor);
	std::cout << "<" << this->target << "> has been pardoned by Zafod Beeblebrox." << std::endl;
}

void 					PresidentialPardonForm::doNothing()
{
	return ;
}