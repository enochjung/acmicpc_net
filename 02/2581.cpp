#include <cstdio>

int m, n;
int sum, min;
bool np[10010] = {1, 1};

int main()
{
	for(int i=2; i*i<=10000; i++)
		if(!np[i])
			for(int j=i*2; j<=10000; j+=i)
				np[j] = true;

	scanf("%d %d", &m, &n);
	for(int i=m; i<=n; i++)
		if(!np[i])
		{
			if(min == 0)
				min = i;
			sum += i;
		}

	if(min == 0)
		printf("-1\n");
	else
		printf("%d %d\n", sum, min);
	return 0;
}
