#include <cstdio>
#define N 1000000

int m, n;
int sum, min;
bool np[N+10] = {1, 1};

int main()
{
	for(int i=2; i*i<=N; i++)
		if(!np[i])
			for(int j=i*2; j<=N; j+=i)
				np[j] = true;

	scanf("%d %d", &m, &n);
	for(int i=m; i<=n; i++)
		if(!np[i])
			printf("%d\n", i);
	return 0;
}
