#include <cstdio>

int t, n, m;

int main()
{
	for (scanf("%d", &t); t--;)
	{
		scanf("%d %d", &n, &m);
		while (m--)
			scanf("%*d %*d");

		printf("%d\n", n - 1);
	}

	return 0;
}