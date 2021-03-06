#include <cmath>
#include <limits>

template <typename T>
bool isSame(const T a, const T b)
{
	return a == b ? true : false;
}

template <>
bool isSame<float>(const float a, const float b)
{
	return fabs(a - b) < std::numeric_limits<float>::epsilon() ? true : false;
}

template <>
bool isSame<double>(const double a, const double b)
{
	return fabs(a - b) < std::numeric_limits<double>::epsilon() ? true : false;
}
