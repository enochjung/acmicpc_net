#include <cstdio>
#include <cstring>
#define M 2000

int d[M][M];

int nCr(int n, int r, int mod)
{
	if (n < r)
		return 0;
	if (n == 1 || r == 0 || r == n)
		return 1;
	if (d[n][r] == -1)
		d[n][r] = (nCr(n - 1, r - 1, mod) + nCr(n - 1, r, mod)) % mod;
	return d[n][r];
}

int lucas(long long n, long long k, int p)
{
	long long res = 1;
	while (n > 0 || k > 0)
	{
		res = res * nCr(n % p, k % p, p) % p;
		n /= p;
		k /= p;
	}
	return res;
}

int main()
{
	long long n, k;
	int m;

	memset(d, -1, sizeof(d));
	scanf("%lld %lld %d", &n, &k, &m);
	printf("%d", lucas(n, k, m));

	return 0;
}