//O(logn)
unsigned long long fastPow(unsigned long long x, unsigned long long n) {
    if (n == 0)
        return 1;

    if (n == 1)
        return x;
  
    if (n % 2) 
        return x * fastPow(x, n - 1);
	
    unsigned long long ret = fastPow(x, n / 2);
    return ret * ret;
}
