#include <stdio.h>

int t, n, m;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		int d[10010] = {1};

		scanf("%d", &n);
		while(n--)
		{
			int c;
			scanf("%d", &c);

			for(int i=0; i+c<=10000; i++)
				d[i+c] += d[i];
		}
		scanf("%d", &m);

		printf("%d\n", d[m]);
	}
	
	return 0;
}
