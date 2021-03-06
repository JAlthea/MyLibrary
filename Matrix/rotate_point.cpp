#include <type_traits>

/*
is_arithmetic : integer type, floating point number type
*/
template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, std::pair<T, T>> rotatePoint_90(const std::pair<T, T> &point)
{
	int m[2][2] = { { 0, -1}, {1, 0} };
	std::pair<T, T> rotatedPoint;
	rotatedPoint.first = m[0][0] * point.first + m[0][1] * point.second;
	rotatedPoint.second = m[1][0] * point.first + m[1][1] * point.second;
	return rotatedPoint;
}
