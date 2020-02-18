const long long m = 1e9;   //custom value
inline long long mod(long long k) { return k >= m ? k %= m : k; }

/* 
Time Complexity : O(logn) 
Conversion of a matrix expression to an algebraic expression
*/
long long fibo(long long n)
{
	long long a = 1, b = 0, p = 0, q = 1, tmpA, tmpB, tmpP, tmpQ;

	while (1)
	{
		if (n <= 0)
			return b;

		if (n % 2 == 0)
		{
			tmpP = mod((p*p) + (q*q));
			tmpQ = mod((q*q) + (2 * p*q));
			p = tmpP;
			q = tmpQ;
			n /= 2;
		}
		else
		{
			tmpA = mod((b*q) + (a*q) + (a*p));
			tmpB = mod((b*p) + (a*q));
			a = tmpA;
			b = tmpB;
			n -= 1;
		}
	}
}

long long sum_fibo(long long n) 
{
	return mod(m + fibo(n + 2) - fibo(2)); 
}

long long sum_fibo(long long a, long long b) 
{ 
	return mod(m + fibo(b + 2) - fibo(a + 1));
}
