#ifndef IGNORE_H
#define IGNORE_H

#include <iostream>

void ignore()
{
	std::cin.ignore(100, '\n');
}

#endif // !IGNORE_H

