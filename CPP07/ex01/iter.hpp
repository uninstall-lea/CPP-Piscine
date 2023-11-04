#pragma once

#include <string>
#include <iostream>
#include <cstddef>

template<typename T>
void	iter(T *array, size_t size, void (*f)(T))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template<typename T>
void	print(T elem)
{
	std::cout << elem << std::endl;
}