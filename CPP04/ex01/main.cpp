#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	std::cout << "\nCreating an array of Animal objects..." << std::endl;
	Animal* animals[10];

	std::cout << "\nCreating 5 Dog objects and 5 Cat objects..." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << std::endl << "---------------------" << std::endl;
	std::cout << "\nTesting deep copy of Dog object..." << std::endl;
	Dog dog1;
	Dog dog2 = dog1;
	if (&dog1 == &dog2)
		std::cout << "Shallow copy" << std::endl;
	else
		std::cout << "Deep copy" << std::endl;

	std::cout << std::endl << "---------------------" << std::endl;
	std::cout << "\nTesting deep copy of Cat object..." << std::endl;
	Cat cat1;
	Cat cat2 = cat1;
	if (&cat1 == &cat2)
		std::cout << "Shallow copy" << std::endl;
	else
		std::cout << "Deep copy" << std::endl;

	std::cout << std::endl << "---------------------" << std::endl;
	std::cout << "\nDeleting the Animal objects..." << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	return (0);
}
