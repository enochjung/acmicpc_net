#include <stdio.h>

int n;
long long d[2][100];

int main()
{
	scanf("%d", &n);

	d[1][1] = 1;
	for(int i=2; i<=n; i++)
	{
		d[0][i] = d[0][i-1]+d[1][i-1];
		d[1][i] = d[0][i-1];
	}

	printf("%lld\n", d[0][n]+d[1][n]);
	return 0;
}
