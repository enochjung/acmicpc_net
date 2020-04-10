#include <stdio.h>

int n, k;
int d[10010];

int main()
{
	scanf("%d %d", &n, &k);

	d[0] = 1;
	while(n--)
	{
		int c;
		scanf("%d", &c);

		for(int i=0; i+c<=k; i++)
			d[i+c] += d[i];
	}

	printf("%d", d[k]);
	
	return 0;
}
