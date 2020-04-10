#include <stdio.h>

int t, n, d[20] = {1};

int main()
{
	for(int i=1; i<=10; i++)
	{
		if(i>0) d[i]+=d[i-1];
		if(i>1) d[i]+=d[i-2];
		if(i>2) d[i]+=d[i-3];
	}

	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}
	return 0;
}
