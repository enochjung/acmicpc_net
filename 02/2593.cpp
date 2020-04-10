#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, m, x[110], y[110], a, b;
int d[100010], f[100010], e[100010];
queue<int> q;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++)
		scanf("%d %d", x+i, y+i);
	scanf("%d %d", &a, &b);

	memset(d, -1, sizeof(d));
	d[b] = 0;
	q.push(b);
	while(!q.empty() && d[a]==-1)
	{
		int k = q.front();
		q.pop();

		for(int i=1; i<=m; i++)
			if(k>=x[i] && (k-x[i])%y[i]==0)
				for(int j=x[i]; j<=n; j+=y[i])
					if(d[j] == -1)
					{
						d[j] = d[k]+1;
						f[j] = k;
						e[j] = i;
						q.push(j);
					}
	}

	if(d[a] == -1)
		printf("-1");
	else
	{
		printf("%d\n", d[a]);
		while(f[a] != 0)
		{
			printf("%d\n", e[a]);
			a = f[a];
		}
	}
	return 0;
}
