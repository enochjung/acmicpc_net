#include <cstdio>

int a, b;

int main()
{
	scanf("%*d %d %d", &a, &b);
	a--, b--;

	for(int i=0;; i++)
	{
		if(a == b)
		{
			printf("%d\n", i);
			return 0;
		}
		a>>=1, b>>=1;
	}
	return 0;
}
