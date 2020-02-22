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
