#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);

	for(int i=n; i>=1; i--)
	{
		for(int j=0; j<n-i; j++)
			printf(" ");
		for(int j=0; j<i*2-1; j++)
			printf("*"); 
		printf("\n");
	}
	return 0;
}
