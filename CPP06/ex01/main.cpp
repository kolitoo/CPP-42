#include "Serializer.hpp"

int	main(void)
{
	Data* originalData = new Data();

	std::cout << originalData << std::endl;
	uintptr_t serializedValue = Serializer::serialize(originalData);
	std::cout << serializedValue << std::endl;
	Data* deserializedData = Serializer::deserialize(serializedValue);
	std::cout << deserializedData << std::endl;

	delete originalData;
	return (0);
}