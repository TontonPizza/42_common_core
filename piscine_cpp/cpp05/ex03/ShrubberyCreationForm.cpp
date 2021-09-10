#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(): Form("shrubbery creation", 156, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target): Form("shrubbery creation", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const  ShrubberyCreationForm & T): Form(T.getName(), 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & T)
{
	this->Form::setStatus(T.getStatus());
	this->target = T.target;
	return (*this);
}


void 					ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->Form::execute(executor);

	std::ofstream destination;
	destination.open((this->target + "_shrubbery").c_str());
	if (destination.fail())
		throw ShrubberyCreationForm::OpeningFileException();
	destination << "      ^                     "<< std::endl;
	destination << "     / \\                   "<< std::endl;
	destination << "    /| |\\       _|  |/  \\/    "<< std::endl;
	destination << "   / | | \\        \\_\\   |/   "<< std::endl;
	destination << "  /  | |  \\          \\/    "<< std::endl;
	destination << " /_ _|_|_ _\\         |    "<< std::endl;
	destination << "     | |             |    "<< std::endl;
	destination << "     | |             |    "<< std::endl;



	destination.close();
}

void 		ShrubberyCreationForm::doNothing()
{
	return ;
}