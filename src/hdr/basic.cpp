#include <basic.hpp>

void must_init(bool test, const char *desc)
{
	if (test) return;

	std::cout << "Couldn't initialize " << desc << "\n";
	exit(1);
};