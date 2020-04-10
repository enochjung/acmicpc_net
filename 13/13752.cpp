#include <cstdio>

int n, k;

int main()
{
	for(scanf("%d",&n); n--;)
	{
		scanf("%d", &k);
		
		while(k--)
			printf("=");
		printf("\n");
	}

	return 0;
}
