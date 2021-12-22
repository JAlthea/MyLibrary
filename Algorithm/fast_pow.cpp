long long fast_pow(int x, int n) {
    if (n == 1)
        return x;
  
    if (n % 2) 
        return x * fast_pow(x, n - 1);
	
    long long ret = f(x, n / 2);
    return ret * ret;
}
