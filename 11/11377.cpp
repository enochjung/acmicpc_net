#include <cstdio>
#include <cstring>
#include <vector>
#define N 2010
#define M 1010

using namespace std;

int n, k, q[M], v[N];
vector<int> e[N];

bool dfs(int x, int lv)
{
	v[x] = lv;

	for(int to : e[x])
		if(!q[to] || (v[q[to]]<lv && dfs(q[to],lv)))
		{
			q[to] = x;
			return true;
		}

	return false;
}

int main()
{
	scanf("%d %*d %d", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		int c;
		scanf("%d", &c);
		while(c--)
		{
			int v;
			scanf("%d", &v);
			e[i].push_back(v);
			e[i+n].push_back(v);
		}
	}

	int res = 0;
	for(int i=1; i<=n; ++i)
		if(dfs(i, i))
			++res;
	int plus = 0;
	for(int i=n+1; i<=n*2; ++i)
		if(dfs(i, i))
		{
			++plus;
			if(plus == k)
				break;
		}

	printf("%d", res+plus);
	return 0;
}
