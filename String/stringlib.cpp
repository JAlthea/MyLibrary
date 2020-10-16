#include <ssteram>
#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> split(std::string &s, char deli)
{
	std::istringstream ss(s);
	std::vector<std::string> result;
	std::string nowString;
	while (std::getline(ss, nowString, deli))
		result.push_back(nowString);
	return result;
}
