#include <cstdio>
#include <cstdlib>

int n;

int main()
{
	scanf("%d", &n);

	for(int i=-n+1; i<n; i++)
	{
		for(int j=0; j<abs(i); j++)
			printf(" ");
		for(int j=0; j<n-abs(i); j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
