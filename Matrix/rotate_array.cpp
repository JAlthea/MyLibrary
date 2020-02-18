vector<vector<int>> rotateArray(vector<vector<int>> &array, int n, int m)
{
	vector<vector<int>> rotatedArray(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rotatedArray[j][n - 1 - i] = array[i][j];
	return rotatedArray;
}
