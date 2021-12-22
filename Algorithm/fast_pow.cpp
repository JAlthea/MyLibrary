long long fastPow(int x, int n) {
    if (n == 1)
        return x;
  
    if (n % 2) 
        return x * fastPow(x, n - 1);
	
    long long ret = f(x, n / 2);
    return ret * ret;
}
