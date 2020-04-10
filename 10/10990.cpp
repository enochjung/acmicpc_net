#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1-i; j++)
			printf(" ");
		printf("*");
		
		if(i > 0)
		{
			for(int j=0; j<i*2-1; j++)
				printf(" ");
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
