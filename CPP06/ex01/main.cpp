#include "Serializer.hpp"

int	main(void)
{
	Data	object;

	std::cout << "Object origin:\t\t\t" << &object << std::endl;
	std::cout << "Object serialize-deserialize:\t" << Serializer::deserialize(Serializer::serialize(&object)) << std::endl;
	
	return (0);
}