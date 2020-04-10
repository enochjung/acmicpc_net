#include <cstdio>

long long a, b;

int gcd(long long p, long long q)
{
	while(p % q)
	{
		long long tmp = q;
		q = p%q;
		p = tmp;
	}
	return q;
}

int main()
{
	scanf("%lld %lld", &a, &b);
	
	int cnt = gcd(a, b);
	for(int i=0; i<cnt; ++i)
		printf("1");
	return 0;
}
