#include <cstdio>

int n, m;

int gcd(int p, int q)
{
	while(p % q)
	{
		int tmp = q;
		q = p%q;
		p = tmp;
	}
	return q;
}

int main()
{
	scanf("%d:%d", &n, &m);
	printf("%d:%d", n/gcd(n,m), m/gcd(n,m));
	return 0;
}
