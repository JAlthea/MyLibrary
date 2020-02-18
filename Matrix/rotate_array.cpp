template <typename T>
vector<vector<T>> rotateArray(vector<vector<T>> &array)
{
	vector<vector<T>> rotatedArray(m, vector<T>(n, 0));
	int n = array.size();
	int m = array[0].size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rotatedArray[j][n - 1 - i] = array[i][j];
	return rotatedArray;
}
