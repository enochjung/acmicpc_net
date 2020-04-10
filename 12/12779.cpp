#include <stdio.h>
#include <math.h>

typedef long long int lli;

lli a, b;

lli gcd(lli i, lli j)
{
	while(i%j)
	{
		lli tmp = j;
		j = i%j;
		i = tmp;
	}
	return j;
}

int main()
{
	scanf("%lld %lld", &a, &b);

	lli p, q;
	p = (lli)sqrt(b) - (lli)sqrt(a);
	q = b - a;

	if(p == 0) return printf("0");

	lli g = gcd(p, q);
	printf("%lld/%lld", p/g, q/g);
}
