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
	std::cout << "\nDeleting the Animal objects..." << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << std::endl << "---------------------" << std::endl;
	std::cout << "\nTesting for deep copy..." << std::endl;
	Cat* chat1 = new Cat();
	chat1->setIdea(0, "time for lunch");
	Cat* chat2 = new Cat(*chat1);
	delete chat1;
	std::cout << chat2->getIdea(0) << std::endl;
	delete chat2;

	return (0);
}
