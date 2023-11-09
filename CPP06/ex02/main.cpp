#include "Base.hpp"
#include <exception>

Base* generate(void) {

	Base* ptr;

	if (rand() % 3 == 0) {
		std::cout << "Generating A" << std::endl;
		ptr = new A();
	}
	else if (rand() % 3 == 1) {
		std::cout << "Generating B" << std::endl;
		ptr = new B();
	}
	else {
		std::cout << "Generating C" << std::endl;
		ptr = new C();
	}

	return (ptr);
}

void identify(Base* p) {

	A* test_a = dynamic_cast<A*>(p);
	B* test_b = dynamic_cast<B*>(p);
	C* test_c = dynamic_cast<C*>(p);

	std::cout << "My actual '*' type is: ";
	if (test_a)
		std::cout << test_a << std::endl;
	else if (test_b)
		std::cout << test_b << std::endl;
	else
		std::cout << test_c << std::endl;
}

void identify(Base& p) {

	std::cout << "My actual '&' type is: ";
	try {
		A& test_a = dynamic_cast<A&>(p);
		(void)test_a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e){};

	try {
		B& test_b = dynamic_cast<B&>(p);
		(void)test_b;
		std::cout << "B" << std::endl;

	}
	catch (std::exception &e){};

	try {
		C& test_c = dynamic_cast<C&>(p);
		(void)test_c;
		std::cout << "C" << std::endl;

	}
	catch (std::exception &e){};
}

int main(void) {

	Base* test = generate();

	identify(test);
	identify(*test);

	delete test;
}