#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <algorithm>

class NumberNotFound : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Number not found in container");
		}
};

template<typename T>
int easyfind(T& container, int nb) {

	typename T::iterator	it = std::find(container.begin(), container.end(), nb);

	if (it == container.end())
		throw NumberNotFound();

	return (*it);
}