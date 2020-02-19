#include <string>

/*
digit : .000 => 3, .01010110 => 8
*/
std::string convertBinaryNumber(double value, int digit)
{
	int n = value;
	value -= (double)n;

	int x = 1;
	while (n > x)
		x += x;

	if (x > n)
		x >>= 1;

	std::string binaryNumber = "";
	while (x)
	{
		binaryNumber += n & x ? '1' : '0';
		x >>= 1;
	}

	if (value != 0.0)
	{
		binaryNumber += '.';
		for (int i = 0; value != 0 && i < digit; i++)
		{
			value *= 2;
			x = value;
			value = value - (double)x;
			binaryNumber += std::to_string(x);
		}
	}

	return binaryNumber;
}
