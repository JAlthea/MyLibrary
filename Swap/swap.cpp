/* XOR swap for Integer */
template <typename T>
std::enable_if_t <std::is_integral_v<T>> swap(T &a, T &b)
{
	a ^= (b ^= (a ^= b));
}

template <typename T>
std::enable_if_t<std::is_floating_point_v<T>> swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}
