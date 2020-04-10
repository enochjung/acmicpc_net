#include <stdio.h>
#include <string.h>

int t, n, m;
int p[1010], q[1010];
int a[1010], b[1010], visited[1010];

bool f(int x, int lv)
{
	visited[x] = lv;

	for(int i=p[x]; i<q[x]; i++)
		if(b[i]==-1 || (visited[b[i]]<lv && f(b[i], lv)))
		{
			a[x] = i;
			b[i] = x;
			return true;
		}

	return false;
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d", &m, &n);
		for(int i=0; i<n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			p[i]=x-1, q[i]=y;
		}
  	
		int res = 0;

		memset(a, -1, sizeof(a));
		memset(b, -1, sizeof(b));
		memset(visited, -1, sizeof(visited));
		for(int i=0; i<n; i++)
			if(a[i]==-1 && f(i, i))
				res++;

		printf("%d\n", res);
	}
	return 0;
}
