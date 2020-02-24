#include <type_traits>

/*
is_arithmetic : integer type, floating point number type
*/

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, bool> greater(const vector<T> &a, const vector<T> &b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			return a[i] > b[i];
	return a[i] > b[i];
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, bool> less(const vector<T> &a, const vector<T> &b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			return a[i] < b[i];
	return a[i] < b[i];
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, bool> greater(const pair<T, T> &a, const pair<T, T> &b)
{
	if (a.first != b.first)
		return a.second > b.second;
	return a.first > b.first;
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, bool> less(const pair<T, T> &a, const pair<T, T> &b)
{
	if (a.first != b.first)
		return a.second < b.second;
	return a.first < b.first;
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, bool> greater(const T &a, const T &b)
{
	return a > b;
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, bool> less(const T &a, const T &b)
{
	return a < b;
}
