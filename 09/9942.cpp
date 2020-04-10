#include <cstdio>

int n;
long long d[1010] = {1, 1, 3};

long long f(int x)
{
	if(d[x] == 0)
		d[x] = f(x-2)*2+3;
	return d[x];
}

int main()
{
	int tt = 1;
	while(scanf("%d", &n) != EOF)
	{
		printf("Case %d: %lld\n", tt, f(n));
		++tt;
	}

	return 0;
}
