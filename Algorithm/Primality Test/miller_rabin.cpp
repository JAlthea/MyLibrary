#include <cstdio>
#include <cmath>

int expmod(int base, int n, int m)
{
	if (n == 0) 
		return 1;
	else if ((n != m - 1) && (n != 1) && (n*n % m == 1)) 
		return 0;
	else if (n % 2 == 0) 
		return (int)pow(expmod(base, n / 2, m), 2) % m;
	else 
		return (base * expmod(base, n - 1, m)) % m;
}

bool millerRabinTest(int n, int a)
{
	if (a == 0) 
		return true;

	int tmp = expmod(a, n - 1, n);
	if (tmp == 0) 
		return false;
	else if (tmp == 1) 
		return millerRabinTest(n, a - 1);
	else 
		return false;
}

bool passMiller(int n)
{
	return millerRabinTest(n, n - 1);
}

/*
int main()
{
	if (passMiller(11)) 
		printf("true");
	else 
		printf("false");
}
*/
