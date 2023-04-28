#include <iostream>

int	main( void ) {

	std::string	brain		= "HI THIS IS BRAIN";
	std::string	*stringPtr 	= &brain;
	std::string	&stringRef	= brain;

	std::cout << "Address:\n";
	std::cout << &brain		<< std::endl;
	std::cout << stringPtr	<< std::endl;
	std::cout << &stringRef << std::endl;

	std::cout << "Value:\n";
	std::cout << brain		<< std::endl;
	std::cout << *stringPtr << std::endl;
	std::cout << stringRef	<< std::endl;
}