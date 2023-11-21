#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	int	value;
};

class Serializer
{
	public:
		Serializer(void);
		Serializer(Serializer const& substitue);
		~Serializer(void);

		Serializer&	operator=(Serializer const& substitue);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
