#include <cstdio>
#include <cstdlib>

int n;

int main()
{
	scanf("%d", &n);

	for(int i=-(n-1); i<=(n-1); i++)
	{
		for(int j=0; j<n-1-abs(i); j++)
			printf("* ");
		for(int j=0; j<abs(i)*4+1; j++)
			printf("*");
		for(int j=0; j<n-1-abs(i); j++)
			printf(" *");

		printf("\n");

		if(i < n-1)
		{
			int t = i<0? -i : i+1;

			for(int j=0; j<n-t; j++)
				printf("* ");
			for(int j=0; j<(t-1)*4+1; j++)
				printf(" ");
			for(int j=0; j<n-t; j++)
				printf(" *");
			
			printf("\n");
		}
	}
	return 0;
}
