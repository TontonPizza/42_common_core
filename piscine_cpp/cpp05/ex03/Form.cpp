#include "Form.hpp"


Form::Form(): name("Anon"), gradeToSign(1), gradeToExecute(1), status(false)
{
}

Form::Form(std::string name, int toSign, int toExec): name(name), gradeToSign(toSign), gradeToExecute(toExec), status(false)
{
	checkValue(toSign);
	checkValue(toExec);
}

Form::Form(const Form & T): name(T.getName()), gradeToSign(T.getSignGrade()), gradeToExecute(T.getExecGrade()), status(T.getStatus())
{
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (this->name);
}

int 		Form::getExecGrade() const
{
	return (this->gradeToExecute);
}

int 		Form::getSignGrade() const
{
	return (this->gradeToSign);
}

bool 		Form::getStatus() const
{
	return this->status;
}

void 		Form::setStatus(bool st)
{
	this->status = st;
}

void 			Form::checkValue(int val)
{
	if (val < 1)
		throw Form::GradeTooHighException();
	if (val > 150)
		throw Form::GradeTooLowException();
}


void 	Form::beSigned(Bureaucrat &B)
{
	B.signForm(this);
	if (B.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->setStatus(true);
}

void	Form::execute(const Bureaucrat &executor) const
{
	if (this->getStatus() == false)
		throw Form::NotSignedException();
	else if (executor.getGrade() > this->gradeToExecute)
		throw Form::GradeTooLowException();
}

Form & Form::operator=(const Form & T)
{
		setStatus(T.getStatus());
		return (*this);
}

std::ostream & operator<<(std::ostream & os, Form & T)
{
	os << "Form <" << T.getName() << "> : [sign level = " << T.getSignGrade() <<"] ";
	os << "[exec level = " << T.getExecGrade() << "] ";
	os << "[status = " << T.getStatus() << "]" << std::endl;
	return os;
}