vector<string> split(const string &s, char deli) {
    istringstream ss(s);
    vector<string> result;
    string nowString;
	
    while (getline(ss, nowString, deli))
        result.push_back(nowString);
	
    return result;
}

vector<string> splitBlank(const string &s) {
    stringstream ss(s);
    vector<string> result;
    string nowString;

    while (ss >> nowString) 
        result.push_back(nowString);

    return result;
}

int timeToInt(const string &stringTimeFormat) {
    vector<string> s = split(stringTimeFormat, ':');
    if (s.empty()) 
        return -1;
    
    // hh
    if (s.size() == 1) 
        return stoi(s[0]);
    
    // hh:mm
    if (s.size() == 2) 
        return 60 * stoi(s[0]) + stoi(s[1]);
    
    // hh:mm:ss
    if (s.size() == 3) 
        return 3600 * stoi(s[0]) + 60 * stoi(s[1]) + stoi(s[2]);
    
    // not supported
    return -1;
}
