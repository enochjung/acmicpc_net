#include <cstdio>
#define N 10000

int t, n;
bool np[N+10] = {1, 1};

int main()
{
	for(int i=2; i*i<=N; i++)
		if(!np[i])
			for(int j=i*2; j<=N; j+=i)
				np[j] = true;

	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);

		for(int i=n/2; i>=2; i--)
			if(!np[i] && !np[n-i])
			{
				printf("%d %d\n", i, n-i);
				break;
			}
	}
	return 0;
}
