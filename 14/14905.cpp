#include <cstdio>

int n;

int main()
{
	while(scanf("%d",&n) != 0)
	{
		if(n < 8)
		{
			printf("Impossible\n");
			continue;
		}
	}
	return 0;
}
