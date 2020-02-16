typedef long long ll;
const ll m = 1e9;   //optional
inline ll mod(ll k) { return k >= m ? k %= m : k; }

ll fibo(ll n)
{
	ll a = 1, b = 0, p = 0, q = 1, tmpA, tmpB, tmpP, tmpQ;
    
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

ll sum_fibo(ll n) { return mod(m + fibo(n + 2) - fibo(2)); }

ll sum_fibo(ll a, ll b) { return mod(m + fibo(b + 2) - fibo(a + 1)); }

