

//  Write a program for a guessing game. Game should give user 7 tries to 
//	guess a random number between 1 and 100.

//Preprocessor Directives
//Standard Libraries
#include <iostream>
#include <random>	//needed for PRNG
#include <limits>
#include <string>   //allows for std::string
//Header files
#include "ignore.h" 
#include "tower.h"
#include "dosomemath.h"


//Aliases
using AliasNumber = int32_t;

//Forward Declarations (Function Prototypes)
std::string enterName();
char whatGame();
bool wantToPlay();
bool playAgain();
bool playGame(const int& guesses, int ranNum);
		//pass by lvalue reference. Dont need it here because copy of int is cheap (use it for struct/classes/and other stuff like that enums stuff that can be expensive to copy))
		//but just wanted to put it somewhere to look at it. Good for passing 'things'
		//that would be expensive to copy. Also, good when you need to manipulate what you
		//are passing through (as long as you dont use a pass by const lvalue reference (which is what is regularly prefered). that's neat!
AliasNumber getRandomNum();
void fizzBizzPopGame(int number); // Even with the below delete specified functions - int will try and convert... So what's the point fo deleted funcitons?
void fizzBizzPopGame(double) = delete; // DELETE SPECIFIER: In cases where we have a function that we explicitly do not want to be callable
void fizzBizzPopGame(char) = delete;

// Got rid of doSomeMath.cpp for "dosomemath.h" with template 
//	so no need for the forward declarations 
//int doSomeMath(int int1=0, int int2=0, char sym='+');
//double doSomeMath(double int1, double int2, char sym);
 

class KidsFavoriate
{
	std::string m_lolipop{};
	std::string m_color{};
	int m_favNum{};
	std::string m_name{};

public:

	void setLolipop(std::string_view lolipop) { m_lolipop = lolipop; }
	void setColor(std::string_view color) { m_color = color; }
	void setNum(int num) { m_favNum = num; }
	void setName(std::string name) { m_name = name; }

	std::string_view getLolipop() const { return m_lolipop; }
	std::string_view getColor() const { return m_color; }
	std::string_view getName() const { return m_name; }
	int getFavNum() const { return m_favNum; }
};

void print(const KidsFavoriate& kid)
{
	std::cout << kid.getName() << "'s favoriate color is " << kid.getColor()
		<< '\n' << "Her favoriate number is " << kid.getFavNum()
		<< '\n' << "And she likes to eat " << kid.getLolipop() << " lolipops." << '\n';
}





int monsterDieRoll()
{
	std::mt19937 mt{ std::_Random_device() };
	std::uniform_int_distribution uni(1, 6);
	int dieRoll{ uni(mt) };

	return dieRoll;
}



//Namespaces are used to organize code into logical groups and to prevent name collisions.
namespace Foo
{
	int addSome(int x, int y)
	{
		return x + y;
	}
}
namespace Goo
{
	int subtractSome(int x, int y)
	{
		return x - y;
	}
}







namespace Monster {
	//enumerations are compile time constants. They are constwxpr
	enum MonsterType : std:: int16_t//enumeration (has global scope) // can also specifiy UNDERFLYING base type if needed
	{	//enumerators
		//ENUMERATIONS UNDERLYING TYPE (base) : is the specific integral type used to represent the values of enuemerators
		orc = -11,        // enumerators can be assigned their integral values and they can be -. prints = -11 (enum class does not have integral values: prefer them unless you have some good reason not to, like you want the integral number for some weird reason)
		goblin,		 // prints -9. will ++ to previous integral conversion if not defined
		troll,
		ogre,
		skeleton,
		mummy,// prints 5
	};				// must end with a ;
}
constexpr std::string_view getMonsterName(Monster::MonsterType monster)
{
	switch (monster)
	{
	case -11: return "Orc!";
	case -10: return "Goblin!";
	case -9: return "Troll!";
	case -8: return "Ogre!";
	case -7: return "Skeleton!";
	case -6: return "Mummy!";

	default: return "????";
	}
}


void monsterGame()
{
	int GenOneToSix{ monsterDieRoll()};

	Monster::MonsterType monsterOne{ Monster::orc };
	Monster::MonsterType monsterTwo{ Monster::goblin };
	Monster::MonsterType monsterThree{ Monster::troll };
	Monster::MonsterType monsterFour{ Monster::ogre };
	Monster::MonsterType monsterFive{ Monster::skeleton };
	Monster::MonsterType monsterSix{ Monster::mummy };

	if (GenOneToSix == 1)
	{
		std::cout << "You are fighting a " << getMonsterName(monsterOne);
	}
	if (GenOneToSix == 2)
	{
		std::cout << "You are fighting a " << getMonsterName(monsterTwo);
	}
	if (GenOneToSix == 3)
	{
		std::cout << "You are fight a " << getMonsterName(monsterThree);
	}
	if (GenOneToSix == 4)
	{
		std::cout << "You are fight a " << getMonsterName(monsterFour);
	}
	if (GenOneToSix == 5)
	{
		std::cout << "You are fight a " << getMonsterName(monsterFive);
	}
	if (GenOneToSix == 6)
	{
		std::cout << "You are fight a " << getMonsterName(monsterSix);
	}
}


int main()
{
	KidsFavoriate charlie;

	charlie.setLolipop("lime");
	charlie.setColor("Yellow");
	charlie.setNum(12);
	charlie.setName("Charlie");

	KidsFavoriate liv;

	liv.setLolipop("cherry");
	liv.setColor("red");
	liv.setNum(2);
	liv.setName("Liv");

	std::cout << "int" << sizeof(5) << '\n'
		<< "unsinged int" << sizeof(5u) << '\n'
		<< "long" << sizeof(5l) << '\n'
		<< "char" << sizeof('y') << '\n'
		<< "long long" << sizeof(5ll) << '\n'
		<< "double" << sizeof(2.3434) << '\n'
		<< "float" << sizeof(2.3434f) << '\n'
		<< "bool" << sizeof(true) << '\n';

	//Placed here just to look at some namespace function calls. 
	//Showing how the scope resolution operator allows us to eplicitly pick which namespace 
	//	we want to look in.
	std::cout << Foo::addSome(4, 5) << '\n';
	std::cout << Goo::subtractSome(3, 2) << '\n';

	
	[[maybe_unused]] const int exampleOfUnused{ 12345 };
	// gets rid of compiler warniings about variable not being set but not used?

	mainMenu: 
	//First the prgram asks if the user would like to play a game
	bool play{ wantToPlay() };

	//While loop is true, user can play games
	while (play)
	{
		//Get users name to make game more interactive
		std::string name{ enterName() };

		std::cout << "Okay " << name << ". What game would you like to play?" << "\n";

		//Give user game options
		 int pickGame{ whatGame() };
		
		if(pickGame == 'a')
		{
							//zero initialized guesses to try out a default argument
			constexpr int guesses{7}; //using suffix L for no reason. Just to remember I can.
								//at compile time I dont think this will be changed because the complier would think thats dumb, which it is?

			//lvalue & rvalue test (take its address using operator&. 
			//    If it compilies then you know its an lvalue)
			auto lvalue{ &guesses };
			auto size{ sizeof(lvalue) };
			// & evaluates the binary value
			std::cout << '\t' << lvalue << '\n' <<
				size << '\n';

			std::string otherlvalue{ "Hello world!" };
			std::cout << '\t' << otherlvalue << '\n';

			do
			{
				std::cout << "Okay. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

				//Made types auto just to make it look clearer
				auto randomNum{ getRandomNum() };           //int

				auto game{ playGame(randomNum, guesses) };  //bool

				if (game)
				{
					std::cout << "Congradulation! You won!\n";
				}
				else
				{
					std::cout << "Sorry, you lose. The number I was thinking of was " << randomNum << ".\n";
				}
			} while (playAgain());
			goto
				mainMenu;
		}
		else if (pickGame == 'b')
		{
			do
			{
				auto height{ getHeight() };  //TYPE DEDUCTION (TYPE INFERENCE) 

				auto seconds{ 0 };			 //Allow compilier to deduce the type of an object from the objects initializer

				while (calculateAndPrintBallHeight(height, seconds) > 0.0)
				{
					++seconds;
				}
			} while (playAgain());
			goto
				mainMenu;
		}
		else if (pickGame == 'c')
		{
			do
			{
				std::cout << "Enter any number to be FizzBizzPopped: ";
				int fizzBizzPopNum{};
				std::cin >> fizzBizzPopNum;

				fizzBizzPopGame(fizzBizzPopNum);
				//fizzBizzPopGame('t'); //When tried to call it referenced the detleted function


			} while (playAgain());
			goto
				mainMenu;
		}
		else if (pickGame == 'd')
		{
			do
			{
				std::cout << "Welcome to the basic math game!\n" << "Enter an integer: ";
				double int1{};
				std::cin >> int1;
				std::cout << "Enter another integer: ";
				float int2{};
				std::cin >> int2;
				std::cout << "Now enter one of the following characters +, -, *, or / : ";
				char sym{};
				std::cin >> sym;

				auto math{ doSomeMath(int1, int2, sym) };

				std::cout << int1 << sym << int2 << " = " << math << '\n';

			} while (playAgain());
			goto
				mainMenu;
		}
		else if (pickGame == 'e')
		{
			do
			{
				using namespace std; //told not to do this... but don't see the harm.

					int space, rows;

					cout << "Enter number of rows: ";
					cin >> rows;

					for (int i = 1, k = 0; i <= rows; ++i, k = 0) {
						for (space = 1; space <= rows - i; ++space) {
							cout << "  ";
						}

						while (k != 2 * i - 1) {
							cout << "* ";
							++k;
						}
						cout << endl;
					}
					return 0;
				
			} while (playAgain());
			goto
				mainMenu;
		}
		else if (pickGame == 'f')
		{
			do
			{
				monsterGame();


			} while (playAgain());
			goto
				mainMenu;
		}
		else if (pickGame == 'g')
		{
			do
			{
				print(liv);

				std::cout << '\n';

				print(charlie);

			} while (playAgain());
			goto
				mainMenu;
				}
	}

	std::cout << "Thank you for coming. Hope to see you soon.";
	
	return 0;
}
