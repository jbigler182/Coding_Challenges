//  GUESSING GAME

//Preprocessor Directives
//Standard Libraries
#include <iostream>
#include <random>
#include <limits>
#include <string>



#ifndef IGNORE_H
#define IGNORE_H

void ignore();

#endif // !IGNORE_H




//Alias & typedef. Two ways of assigning a new name to an exsisting type
using AliasNumber = int32_t;
typedef bool typeDef;




AliasNumber getRandomNum()
{
	std::mt19937 mt{ std::_Random_device() };
	std::uniform_int_distribution evenDis(1, 100);
	AliasNumber ranNum{ evenDis(mt) };
	return ranNum;
}
						//Default argument: if no value is provided for
						//guesses it will default to a value of 7
typeDef playGame(const int& ranNum, int guesses=7)
{								//The default must be the rightmost parameter!
								//This doesn't really work in this instance
									//i just have it here as a reminder that default arguments exsist

	for (AliasNumber count{ 1 }; count <= guesses * 2; count += 2)
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
		std::cout << "If you'd like to play again select 'y'. To be taken to the main menu select 'm' :  ";
		char response{};
		std::cin >> response;

		ignore();

		switch (response)
		{
		case 'y': return true;
		case 'm': return false;
		}
	}
}
