#include <cstdio>

int t, n;
bool np[100010];

int main()
{
	for(int i=2; i<=317; ++i)
		if(!np[i])
			for(int j=i*i; j<=100000; j+=i)
				np[j] = true;

	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		for(int i=2; i<=n; ++i)
			if(!np[i] && n%i==0)
			{
				int cnt = 0;
				while(n%i == 0)
				{
					n /= i;
					++cnt;
				}
				printf("%d %d\n", i, cnt);
			}
	}
	return 0;
}
