#include <ssteram>
#include <string>
#include <vector>
#include <iostream>

vector<string> split(string &s, char deli)
{
	istringstream ss(s);
	vector<string> result;
	string nowString;
	while (getline(ss, nowString, deli))
		result.push_back(nowString);
	return result;
}
