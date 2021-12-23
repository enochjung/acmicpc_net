#include <cstdio>

long long n;
long long res;

void update(long long x)
{
	long long j;
	for (j=x*x; n%j==0; j*=x);
	n /= j/x;
	res *= (j/x - j/x/x);
}

int main()
{
	scanf("%lld", &n);

	res = 1;
	for (long long i=2; i*i<=n; ++i)
		if (n%i == 0)
			update(i);
	if (n > 1)
		update(n);

	printf("%lld\n", res);
	return 0;
}