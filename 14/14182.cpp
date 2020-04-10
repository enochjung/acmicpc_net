#include <stdio.h>

int n;

int main()
{
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;

		if(n <= 1000000)
			printf("%d\n", n);
		else if(n <= 5000000)
			printf("%d\n", n/10*9);
		else
			printf("%d\n", n/10*8);
	}
	return 0;
}
