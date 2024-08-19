#include <iostream>
#include <random>
#include <limits>
#include <string>
#include "ignore.h"
#include "tower.h"

using AliasNumber = int32_t;


AliasNumber getRandomNum()
{
	std::mt19937 mt{ std::_Random_device() };
	std::uniform_int_distribution evenDis(1, 100);
	AliasNumber ranNum{ evenDis(mt) };
	return ranNum;
}

bool playGame(int guesses, int ranNum)
{

	for (AliasNumber count{ 0 }; count <= guesses * 2; count += 2)
	{
		std::cout << "Guess " << count << ": ";
		int userGuess{};
		std::cin >> userGuess;

		if (!std::cin || userGuess >= 101 || userGuess < 0)
		{
			std::cin.clear();
			ignore();

			std::cout << "That is not a valid input. You have wasted one of your guesses you fool!\n";

			continue;
		}

		ignore();

		if (ranNum > userGuess)
		{
			std::cout << "Your guess is to low!\n";
			continue;
		}
		if (ranNum < userGuess)
		{
			std::cout << "Your guess is to high!\n";
			continue;
		}
		else
			return true;
	}
	return false;
}

bool playAgain()
{
	while (true)
	{
		std::cout << "Would you like to play again? (y/n): ";
		char response{};
		std::cin >> response;

		ignore();

		switch (response)
		{
		case 'y': return true;
		case 'n': return false;
		}
	}
}
