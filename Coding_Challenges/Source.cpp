#include <iostream>
#include <string>
#include <vector>

namespace flagColors
{
	struct USA
	{
		std::string red{ "red" };
		std::string white{ "white" };
		std::string blue{ "blue" };
	};
	enum Mexico
	{
		red,
		white,
		green,
	};
}

int main()
{
	std::vector<std::string> usa(3);
	std::vector<std::string> mex(3);

	usa = { "red", "white", "blue" };

	for (const auto e : usa)
		std::cout << e;

	return 0;
}