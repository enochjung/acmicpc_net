#include <cstdio>
#include <cstring>
#define N 101
#define R 1000000007

int n, l, r;
int d[N][N], c[N][N], a[N];

int fact(int n)
{
	if (n == 0)
		return 1;
	return a[n]==0? a[n]=(1LL*n*fact(n-1))%R : a[n];
}

int nCr(int n, int r)
{
	if (r==0 || r==n)
		return 1;

	if (c[n][r] == 0)
		c[n][r] = (nCr(n-1,r-1) + nCr(n-1,r)) % R;

	return c[n][r];
}

int f(int a, int b)
{
	if (a == 0)
		return 1;
	if (b == 0)
		return 0;

	if (d[a][b] == -1)
	{
		d[a][b] = 0;
		for (int i=b; i<=a; ++i)
		{
			long long res = f(i-1, b-1);
			res = (res * nCr(a-1, i-1)) % R;
			res = (res * fact(a-i)) % R;
			d[a][b] = (d[a][b] + res) % R;
		}
	}

	return d[a][b];
}

int main()
{
	memset(d, -1, sizeof(d));

	scanf("%d %d %d", &n, &l, &r);

	int res = 0;
	for (int i=l; i<=n-r+1; ++i)
	{
		long long val = f(i-1, l-1);
		val = (val * f(n-i, r-1)) % R;
		val = (val * nCr(n-1, i-1)) % R;
		res = (res + val) % R;
	}

	printf("%d\n", res);
	return 0;
}
