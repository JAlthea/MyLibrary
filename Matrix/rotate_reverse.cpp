#include <vector>

template <typename T>
std::vector<T> reverseArray1D(std::vector<T> &array)
{
	int n = array.size();
	std::vector<T> reversedArray(n);
	for (int i = 0; i < n; i++)
		reversedArray[n - 1 - i] = array[i];
	return reversedArray;
}
