/* 2 arguments */
template <typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

template <typename T>
T min(T a, T b)
{
	return a < b ? a : b;
}

/* 3 arguments */
template <typename T>
T max(T a, T b, T c)
{
	return a < b ? b < c ? c : b : a > c ? a : c;
}

template <typename T>
T min(T a, T b, T c)
{
	return a > b ? b > c ? c : b : a < c ? a : c;
}
