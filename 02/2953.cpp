#include <cstdio>

int idx, res;

int main()
{
	for(int i=0; i<5; i++)
	{
		int sum = 0;
		for(int j=0; j<4; j++)
		{
			int v;
			scanf("%d", &v);
			sum += v;
		}
		if(res < sum)
		{
			idx = i;
			res = sum;
		}
	}

	printf("%d %d\n", idx+1, res);
	return 0;
}
