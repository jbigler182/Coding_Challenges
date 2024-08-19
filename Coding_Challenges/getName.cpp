#include <iostream>
#include <string>

std::string enterName()
{
	std::cout << "Great! Whos playing?" << "\n" << "Enter Name: ";
	std::string name{};
	getline(std::cin >> std::ws, name);

	return name;
}