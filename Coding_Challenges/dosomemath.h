#ifndef DOSOMEMATH_H
#define DOSOMEMATH_H

//template <typename T, typename S>
//auto doSomeMath(T int1, T int2, S sym)
//{
//	while (true)
//	{
//		switch (sym)
//		{
//		case '+':
//			return int1 + int2;
//		case '-':
//			return int1 - int2;
//		case '*':
//			return int1 * int2;
//		case '/':
//			return int1 / int2;
//		}
//	}
//}

// This is an ABRIEIVATED TEMPLTE. Cleaner syntax is nice. 
// BUT CANNOT pass two of the same parameter types sooooo
// i had to change int2 to a float (from a double) to get the code to work
// SO it's better because it illiminates the need for template parameter declarations
// but only if we are using all different types in parameter list
auto doSomeMath(auto int1, auto int2, auto sym)
{
	while (true)
	{
		switch (sym)
		{
		case '+':
			return int1 + int2;
		case '-':
			return int1 - int2;
		case '*':
			return int1 * int2;
		case '/':
			return int1 / int2;
		}
	}
}

#endif