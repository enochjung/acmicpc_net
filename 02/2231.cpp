#include <cstdio>

int f(int x)
{
	int sum = x;

	while (x)
	{
		sum += x % 10;
		x /= 10;
	}

	return sum;
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=1; i<n; ++i)
		if (f(i) == n)
		{
			printf("%d\n", i);
			return 0;
		}

	printf("0\n");
	return 0;
}