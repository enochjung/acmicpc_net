#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		if(i&1)
			printf(" ");
		for(int j=0; j<n; j++)
			printf("* ");
		printf("\n");
	}
	return 0;
}
