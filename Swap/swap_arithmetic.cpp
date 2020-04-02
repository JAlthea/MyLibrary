/* XOR swap for Integer type
   Minimum memory usage */
template <typename T>
std::enable_if_t <std::is_integral_v<T>> swap(T &a, T &b)
{
	a ^= (b ^= (a ^= b));
	//Same are the following.
	/*
	a ^= b;
	b ^= a;
	a ^= b;
	*/
}

/* Floating point number type */
template <typename T>
std::enable_if_t<std::is_floating_point_v<T>> swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}
