#pragma once

#pragma once

#include <string>
#include <cstdlib>
#include <iostream>

class	Base {

	private:
		

	public:
		virtual	~Base( void );

};
class	A: public Base {};
class	B: public Base {};
class	C: public Base {};

Base * generate(void) {


}
void identify(Base* p);
void identify(Base& p);