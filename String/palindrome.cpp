
bool isPalindrome(int n)
{
	int tmp = n;
	int cmp = 0;
	while (tmp)
	{
		cmp *= 10;
		cmp += tmp % 10;
		tmp /= 10; 
	}

	return n == cmp;
}

vector<int> makePalindrome(int length)
{
	vector<string> s;
	vector<int> palins;
    
	int left_right = 0;
	while (left_right <= 9)
	{
		s.push_back(to_string(left_right));
		++left_right;
	}
  
	left_right = 0;
	while (left_right <= 9)
	{
		s.push_back(to_string(left_right) + to_string(left_right));
		++left_right;
	}

	int prevSize = 0;
	int nowSize = s.size();
	while (s.back().size() < length)
	{
		bool isExit = false;
		for (int i = prevSize; i < nowSize; ++i)
		{
			if (s[i].size() == length - 1)
			{
				isExit = true;
				break;
			}
			
			left_right = 0;
			while (left_right <= 9)
			{
				s.push_back(to_string(left_right) + s[i] + to_string(left_right));
				++left_right;
			}
		}

		if (isExit) break;
		prevSize = nowSize;
		nowSize = s.size();
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i].front() == '0') continue;
		palins.push_back(stoi(s[i]));
	}

	sort(palins.begin(), palins.end());
	return palins;
}
