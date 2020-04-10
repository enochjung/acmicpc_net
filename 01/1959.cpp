#include <stdio.h>

unsigned m, n;

int main()
{
	scanf("%u %u", &m, &n);

	if(m > n)
	{
		printf("%u\n", n*2-1);
		if(n%2 == 0)
			printf("%u %u\n", n/2+1, n/2);
		else
			printf("%u %u\n", m-n/2, n/2+1);
	}
	else if(m < n)
	{
		printf("%u\n", m*2-2);
		if(m%2 == 0)
			printf("%u %u\n", m/2+1, m/2);
		else
			printf("%u %u\n", m/2+1, n-m/2);
	}
	else
	{
		printf("%u\n", n*2-2);
		if(n%2 == 0)
			printf("%u %u\n", n/2+1, n/2);
		else
			printf("%u %u\n", n/2+1, n/2+1);
	}

	return 0;
}
