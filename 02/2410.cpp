#include <stdio.h>

int n;
int d[1000010] = {1};

int main()
{
	scanf("%d", &n);

	for(int b=1; b<=n; b<<=1)
		for(int i=0; i+b<=n; i++)
			d[i+b] = (d[i+b]+d[i]) % 1000000000;

	printf("%d", d[n]);

	return 0;
}
