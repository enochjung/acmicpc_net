#include <cstdio>

int n, k;

double f(int x)
{
	if (x == 1)
		return (n + 1) / 2.0;

	double roll = f(x - 1);
	return (int)roll / (double)n * roll + (n - (int)roll) / (double)n * ((int)roll + 1 + n) / 2.0;
}

int main()
{
	scanf("%d %d", &n, &k);
	printf("%.7lf\n", f(k));
	return 0;
}