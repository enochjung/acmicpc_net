#include <cstdio>

long long a, b;

long long gcd(long long x, long long y)
{
	while(x % y)
	{
		long long tmp = y;
		y = x%y;
		x = tmp;
	}
	return y;
}

int main()
{
	scanf("%lld %lld", &a, &b);
	printf("%lld", a*b/gcd(a,b));
	return 0;
}
