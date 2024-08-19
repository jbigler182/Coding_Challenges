#include <iostream>


void fizzBizzPopGame(int number)
{
	for (int count{ 1 }; count <= number; ++count)
	{

		bool printNumber{ false };

		const bool& refPrintNumber{ printNumber };
		//const refs are prefered as they work with non-const (like here)
		// const, and rvalue expressions! neat!

		if (count % 3 == 0)
		{
			std::cout << "Fizz";
			printNumber = true;
			//however, if i wanted to use the lvalue reference here I cannot
			//have a const reference obviously. Because the value needs to be
			//changed.
		}
		if (count % 5 == 0)
		{
			std::cout << "Bizz";
			printNumber = true;
		}
		if (count % 7 == 0)
		{
			std::cout << "Pop";
			printNumber = true;
		}
		if (!refPrintNumber)
		{
			std::cout << count;
		}

		std::cout << "\n";
	}
}