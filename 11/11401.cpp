#include <cstdio>
#define MOD 1000000007

int n, k;

int pow(long long a, long long b)
{
	long long r = 1;

	while (b > 1)
	{
		if (b & 1)
			r = r * a % MOD;
		a = a * a % MOD;
		b = b >> 1;
	}

	return a * r % MOD;
}

int nCr(long long n, long long r)
{
	if (r > n - r)
		return nCr(n, n - r);

	long long a = 1;
	for (int i = n; i > n - r; --i)
		a = a * i % MOD;

	long long b = 1;
	for (int i = 2; i <= r; ++i)
		b = b * i % MOD;

	return a * pow(b, MOD - 2) % MOD;
}

int main()
{
	scanf("%d %d", &n, &k);
	printf("%d", nCr(n, k));

	return 0;
}