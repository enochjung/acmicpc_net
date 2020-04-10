#include <stdio.h>

int s, m, n;
long long d;

int main()
{
	scanf("%d %d %d", &s, &m, &n);

	long long a[10000];

	a[1] = 1;
	for(int i=2; i<=s; i++)
	{
		a[i] = 1;
		for(int j=0; j<a[i-1]; j++)
			a[i] = (a[i]*i)%1000000000;
	}
	printf("%lld\n", (a[s]+m)%n);

	return 0;
}
