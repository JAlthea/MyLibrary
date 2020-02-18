pair<int, int> rotatePoint90D(const pair<int, int> &point)
{
	vector<vector<int>> m = { { 0, -1}, {1, 0} };
	pair<int, int> rotatedPoint;
	rotatedPoint.first = m[0][0] * point.first + m[0][1] * point.second;
	rotatedPoint.second = m[1][0] * point.first + m[1][1] * point.second;
	return rotatedPoint;
}