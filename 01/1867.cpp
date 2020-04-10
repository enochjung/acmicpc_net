#include <cstdio>
#include <vector>
#define N 510

using namespace std;

int n, k, v[N], q[N];
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
	scanf("%d %d", &n, &k);
	while(k--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		e[x].push_back(y);
	}

	int res = 0;
	for(int i=1; i<=n; ++i)
		if(dfs(i, i))
			++res;

	printf("%d", res);
	return 0;
}
