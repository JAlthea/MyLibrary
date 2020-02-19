#include <vector>

template <typename T>
std::vector<std::vector<T>> rotateArray2D(std::vector<std::vector<T>> &array)
{
	int n = array.size();
	int m = array[0].size();
	std::vector<std::vector<T>> rotatedArray(m, std::vector<T>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rotatedArray[j][n - 1 - i] = array[i][j];
	return rotatedArray;
}

template <typename T>
std::vector<T> rotateArray1D(std::vector<T> &array)
{
	int n = array.size();
	std::vector<T> rotatedArray(n);
	for (int i = 0; i < n - 1; i++)
		rotatedArray[i + 1] = array[i];
	rotatedArray[0] = array[n - 1];
	return rotatedArray;
}
