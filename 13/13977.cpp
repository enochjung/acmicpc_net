#include <cstdio>
#define N 4000010
#define MOD 1000000007

long long f[N], fi[N];

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

int nCr(int n, int r)
{
	return (f[n] * fi[r] % MOD) * fi[n - r] % MOD;
}

int main()
{
	int m, n, k;

	f[1] = fi[0] = 1;
	for (int i = 2; i <= N; ++i)
		f[i] = f[i - 1] * i % MOD;
	fi[N] = pow(f[N], MOD - 2);
	for (int i = N - 1; i >= 1; --i)
		fi[i] = fi[i + 1] * (i + 1) % MOD;

	for (scanf("%d", &m); m--;)
	{
		scanf("%d %d", &n, &k);
		printf("%d\n", nCr(n, k));
	}

	return 0;
}