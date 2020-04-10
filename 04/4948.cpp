#include <cstdio>
#define N 300000

int n;
bool np[N+10] = {1, 1};

int main()
{
	for(int i=2; i*i<=N; i++)
		if(!np[i])
			for(int j=i*2; j<=N; j+=i)
				np[j] = true;

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
			break;

		int cnt = 0;
		for(int i=n+1; i<=n*2; i++)
			if(!np[i])
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
