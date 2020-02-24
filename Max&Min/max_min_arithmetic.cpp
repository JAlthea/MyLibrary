#include <type_traits>

/*
is_arithmetic : integer type, floating point number type
*/

/* 2 arguments */
template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, T> max(T a, T b)
{
	return a > b ? a : b;
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, T> min(T a, T b)
{
	return a < b ? a : b;
}

/* 3 arguments */
template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, T> max(T a, T b, T c)
{
	return a < b ? b < c ? c : b : a > c ? a : c;
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, T> min(T a, T b, T c)
{
	return a > b ? b > c ? c : b : a < c ? a : c;
}
