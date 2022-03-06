vector<string> split(const string &s, char deli) {
	istringstream ss(s);
	vector<string> result;
	string nowString;
	while (getline(ss, nowString, deli))
		result.push_back(nowString);
	return result;
}
