// Knapecz, Adam - 1DAE11
#include "pch.h"
#include <iostream>
#include <string>

int main()
{
	std::string s{
		"One morning, when Gregor Samsa woke from troubled dreams, he found himself transformed in his bed into a horrible vermin. He lay on his armour-like back, and if he lifted his head a little he could see his brown belly, slightly domed and divided by arches into stiff sections. The bedding was hardly able to cover it and seemed ready to slide off any moment. His many legs, pitifully thin compared with the size of the rest of him, waved about helplessly as he looked."
	};

	std::cout << "-- Explore string class --" << std::endl;
	std::cout << s << std::endl;
	std::cout << std::endl;

	std::cout << "size: " << s.size() << std::endl;
	std::cout << "length: " << s.length() << std::endl;
	std::cout << std::endl;

	const char* pS{s.c_str()};
	for (std::size_t idx{}; idx < s.length(); ++idx)
	{
		std::cout << pS[idx] << '_';
	}
	std::cout << std::endl << std::endl;

	std::cout << "Capacity: " << s.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "First character using []: " << s[0] << std::endl;
	std::cout << "Last character using []: " << s[s.length() - 1] << std::endl;
	std::cout << "First character using at: " << s.at(0) << std::endl;
	std::cout << "Last character using at: " << s.at(s.length() - 1) << std::endl;
	std::cout << std::endl;

	std::cout << "The string to search for in the above? ";
	std::string userInput;
	std::cin >> userInput;
	std::cout << "Occurances of '" << userInput << "' at:" << std::endl;
	std::size_t pos{s.find(userInput)};
	while (pos != std::string::npos)
	{
		std::cout << pos << ' ';
		pos = s.find(userInput, pos + 1);
	}
	std::cout << "In reverse order:" << std::endl;
	pos = s.rfind(userInput);
	while (pos != std::string::npos)
	{
		std::cout << pos << ' ';
		pos = s.rfind(userInput, pos - 1);
	}
	std::cout << std::endl << std::endl;

	std::cout << "The string you wnat to replace by * in the above text? ";
	std::cin >> userInput;
	pos = s.find(userInput);
	std::string replacer(userInput.length(), '*');
	while (pos != std::string::npos)
	{
		s.replace(pos, userInput.length(), replacer);
		pos = s.find(userInput, pos + 1);
	}
	std::cout << s;
	std::cout << std::endl << std::endl;

	std::cout << "The string you want to erase from the above text? ";
	std::cin >> userInput;
	pos = s.find(userInput);
	while (pos != std::string::npos)
	{
		s.erase(pos, userInput.length());
		pos = s.find(userInput, pos + 1);
	}
	std::cout << s;
	std::cout << std::endl << std::endl;

	std::cout << "Size: " << s.size() << std::endl;
	std::cout << "Length: " << s.length() << std::endl;
	std::cout << "Capacity: " << s.capacity() << std::endl;
}
