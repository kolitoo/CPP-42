#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer constructor called" << std::endl;
}
Serializer::Serializer(Serializer const& substitue)
{
	if (this != &substitue)
	{
	}
}
Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called" << std::endl;
}
Serializer&	Serializer::operator=(Serializer const& substitue)
{
	if (this != &substitue)
	{
	}
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}