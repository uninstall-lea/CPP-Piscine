#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const& src )
	: AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target) {

	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( ShrubberyCreationForm const& rhs ) {

	(void) rhs;
	return (*this);
}

/*----------------------------------------------------------------------------*/

void	ShrubberyCreationForm::beExecuted( void ) const {

	std::ofstream	outFile;
	std::string		outFileName = _target + "_shrubbery";

	outFile.open(outFileName.c_str());
	if (outFile.fail())
		throw ErrorOpeningFile();
	outFile << TREE;
	outFile.close();
}