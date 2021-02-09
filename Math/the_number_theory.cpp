/* Integer type : char, unsigned char, wchar_t, short, int, long, long long, ...

*/

// __gcd(a, b) in C++ header '#include <algorithm>'
template <typename T>
std::enable_if_t<std::is_integral_v<T>, T> GCD(T a, T b)
{
    return b ? GCD(b, a % b) : a;
}

std::enable_if_t<std::is_integral_v<T>, T> LCM(T a, T b)
{
    return a * b / GCD(a, b);
}
