/* XOR swap for Integer */
template <typename T>
void swap(T &a, T &b)
{
    a ^= (b ^= (a ^= b));
}

template <>
void swap<double>(double &a, double &b)
{
    double c = a;
    a = b;
    b = c;
}

template <>
void swap<float>(float &a, float &b)
{
    float c = a;
    a = b;
    b = c;
}
