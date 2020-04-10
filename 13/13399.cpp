#include <cstdio>
#define N 200010
#define M 100010

int n, m, a[M];
bool visited[N];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
		scanf("%d", a+i);

	for(int i=m-1; i>=0; --i)
		if(!visited[a[i]])
		{
			visited[a[i]] = true;
			printf("%d\n", a[i]);
		}

	for(int i=1; i<=n; ++i)
		if(!visited[i])
			printf("%d\n", i);
	return 0;
}
