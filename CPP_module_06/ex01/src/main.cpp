#include <iostream>
#include <string>
#include "Serializer.hpp"
#include <iostream>

#define EXIT_SUCCESS 0
// #define EXIT_FAILURE 1

int	main(void)
{
	Data		data;
	Data		*result;
	uintptr_t	raw;

	data.name = "mr. Split";
	data.age = 30;
	data.next = NULL;

	raw = Serializer::serialize(&data);
	result = Serializer::deserialize(raw);

	std::cout << "Original address:     " << &data << std::endl;
	std::cout << "Deserialized address: " << result << std::endl;
	std::cout << "Raw value:            " << raw << std::endl;
	std::cout << "Data:" << std::endl;
	std::cout << *result << std::endl;

	if (result == &data)
		std::cout << "Serialization successful" << std::endl;
	else
		std::cout << "Serialization failed" << std::endl;
	return (EXIT_SUCCESS);
}
