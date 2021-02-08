
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

void makePalindrome(int length)
{
	vector<string> ret;
	vector<int> palins;
    
	int left_right = 0;
	while (left_right <= 9)
	{
		ret.push_back(to_string(left_right));
		++left_right;
	}
  
	left_right = 0;
	while (left_right <= 9)
	{
		ret.push_back(to_string(left_right) + to_string(left_right));
		++left_right;
	}

	int prevSize = 0;
	int nowSize = ret.size();
	while (ret.back().size() < length)
	{
		bool isExit = false;
		for (int i = prevSize; i < nowSize; ++i)
		{
			if (ret[i].size() == length - 1)
			{
				isExit = true;
				break;
			}
			
			left_right = 0;
			while (left_right <= 9)
			{
				ret.push_back(to_string(left_right) + ret[i] + to_string(left_right));
				++left_right;
			}
		}

		if (isExit) break;
		prevSize = nowSize;
		nowSize = ret.size();
	}

	for (int i = 0; i < ret.size(); ++i)
	{
		if (ret[i].front() == '0') continue;
		palins.push_back(stoi(ret[i]));
	}

	sort(palins.begin(), palins.end());
	return palins;
}
