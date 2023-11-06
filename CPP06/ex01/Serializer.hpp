#pragma once

#include <string>
#include <stdint.h>
#include <iostream>

typedef struct s_Data
{
	int	a;
	int	b;
} Data;


class  Serializer {

	private:

	public:
		static	uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
};
