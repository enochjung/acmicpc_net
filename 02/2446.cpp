#include <cstdio>
#include <cstdlib>

int n;

int main()
{
	scanf("%d", &n);
	
	for(int i=-n+1; i<n; i++)
	{
		for(int j=0; j<n-1-abs(i); j++)
			printf(" ");
		for(int j=0; j<abs(i)*2+1; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
