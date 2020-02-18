/* XOR swap for Integer */
void swap(int &a, int &b)
{
    a ^= (b ^= (a ^= b));
}
