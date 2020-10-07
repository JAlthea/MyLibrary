#include <vector>
using namespace std;

/* 
if size of data is small, it will be useful method.
example of actual use : C++ / std::sort()
*/

template <class RandomIt>
inline void insertionSort(RandomIt first, RandomIt last)
{
	_Adl_verify_range(first, last);
	const auto UFirst = _Get_unwrapped(first);
	const auto ULast = _Get_unwrapped(last);
	for (auto i = UFirst + 1; i < ULast; ++i)
	{
		auto value = *i;
		auto j = i - 1;
		while (j >= 0 && *j > value)
		{
			*(j + 1) = *j;
			j--;
		}
		*(j + 1) = value;
	}
}

/*
int main()
{
	vector<int> arr = { 1, 3, 2, 5, 4 };
	insertionSort(arr.begin(), arr.end());
	for (auto &a : arr) cout << a << ' ';
}
*/
