#include <iostream>

void ignore();

bool wantToPlay()
{
	std::cout << "Would you like to play a game? (y/n): ";
	while (true)
	{
		char response{};
		std::cin >> response;

		if (response == 'y' || response == 'n')
		{
			switch (response)
			{
			case 'y': return true;
			case 'n': return false;
			}
		} else
			std::cin.clear();
			ignore();

			std::cout << "That is not a valid input." << "\n" << "Please enter 'y' or 'n': ";

			continue;
	}
}

char whatGame()
{
	while (true)
	{

		std::cout << "For Guessing Game, select 1" << "\n" <<
			"For Ball Drop, select 2" << "\n" <<
			"For FizzBizzPop, select 3" << "\n" <<
			"For Math Game, select 4" << "\n" <<
			"For Pyramid Game, select 5" << "\n"
			"To fight a random monster, select 6" << "\n"
			"Get to know my kids, select 7" << "\n";

		char response{};
		std::cin >> response;
	
		switch (response)
		{
		case '1': return 'a';
		case '2': return 'b';
		case '3': return 'c';
		case '4': return 'd'; 
		case '5': return 'e';
		case '6': return 'f';
		case '7': return 'g';
		}
	}
}