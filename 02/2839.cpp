#include <stdio.h>

int n;

int main()
{
	scanf("%d", &n);
	for(int i=n/5; i>=0; i--)
		if((n-i*5)%3 == 0)
		{
			printf("%d\n", i+(n-i*5)/3);
			return 0;
		}

	printf("-1\n");
	return 0;
}
