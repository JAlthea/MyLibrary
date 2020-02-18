#include <vector>
using namespace std;

template <typename T>
vector<vector<T>> rotateArray(vector<vector<T>> &array)
{
	int n = array.size();
	int m = array[0].size();
	vector<vector<T>> rotatedArray(m, vector<T>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rotatedArray[j][n - 1 - i] = array[i][j];
	return rotatedArray;
}
