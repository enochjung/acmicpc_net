#include <cstdio>
#include <cstring>
#include <vector>
#define N 1010

using namespace std;

int n, m, q[N], v[N];
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
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		int c;
		scanf("%d", &c);
		while(c--)
		{
			int v;
			scanf("%d", &v);
			e[i].push_back(v);
		}
	}

	int res = 0;
	for(int i=1; i<=n; ++i)
		if(dfs(i, i))
			++res;

	printf("%d", res);
	return 0;
}
