#include <vector>

template <typename T>
std::vector<std::vector<T>> rotateArray(std::vector<std::vector<T>> &array)
{
	int n = array.size();
	int m = array[0].size();
	std::vector<std::vector<T>> rotatedArray(m, std::vector<T>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rotatedArray[j][n - 1 - i] = array[i][j];
	return rotatedArray;
}
