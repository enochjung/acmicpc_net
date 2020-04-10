#include <cstdio>

int d[110], sum;

int main()
{
	for(int i=0; i<10; i++)
	{
		int v;
		scanf("%d", &v);
		d[v/10]++;
		sum += v;
	}

	int res, max=0;
	for(int i=1; i<100; i++)
		if(max < d[i])
		{
			max = d[i];
			res = i;
		}

	printf("%d\n%d", sum/10, res*10);
	return 0;
}
