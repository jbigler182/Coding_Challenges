#ifndef TOWER_CPP
#define TOWER_CPP



#include <iostream>
#include <random>
#include <limits>
#include <string>
#include "ignore.h"

double getHeight()
{
	while (true)
	{
		std::cout << "Enter the height of the tower in meters: ";
		double height{};
		std::cin >> height;

		if (!std::cin)
		{
			std::cin.clear(); //reset error flags
			ignore();		  //remove erroneous

			std::cout << "That is not a valid input." << "\n" << "\n" << "Input must be an integer. Try again.\n";

			continue;
		}
		ignore();
		return height;
	}
}

double getNewHeight(double height, double seconds)
{
	constexpr double gravity{ 9.8 };
	double dropRate{ gravity * (seconds * seconds) / 2 };
	double newHeight{ height - dropRate };
	return newHeight;
}

void printBallHeight(double newHeight, int seconds)
{
	if (newHeight > 0)
	{
		std::cout << "At " << seconds << " seconds, the ball is " << newHeight << " meters high.\n";
	}
	else
		std::cout << "Your ball is on the ground.";
}

double calculateAndPrintBallHeight(double height, int seconds)
{
	double newHeight{ getNewHeight(height, seconds) };
	printBallHeight(newHeight, seconds);

	return newHeight;
}

#endif // !TOWER_CPP


