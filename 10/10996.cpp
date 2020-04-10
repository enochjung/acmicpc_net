#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);

	if(n == 1)
	{
		printf("*");
		return 0;
	}

	for(int i=0; i<n*2; i++)
	{
		if(i&1)
			printf(" ");
		for(int j=0; j<(n+1-(i&1))/2; j++)
			printf("* ");
		printf("\n");
	}
	return 0;
}
