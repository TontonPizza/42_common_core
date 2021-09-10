#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("robotomy request", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target): Form("robotomy request", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const  RobotomyRequestForm & T): Form(T.getName(), 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & T)
{
	this->Form::setStatus(T.getStatus());
	this->target = T.target;
	return (*this);
}


void 					RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->Form::execute(executor);
	std::cout << "BRRRRRRRR" << std::endl;
	if (system("aplay drill.wav 1>/dev/null 2>/dev/null") == -1 || rand() % 2 == 0)
	{
		std::cout << "robotomization failed" << std::endl;
		throw RobotomyRequestForm::RobotomyException();
	}
	else
	{
		std::cout << "<" << this->target << "> has been robotomized" << std::endl;
	}
}

void 					RobotomyRequestForm::doNothing()
{
	return ;
}