#include <cstdio>
#include <cstring>
#include <vector>
#define N 1501

using namespace std;

int n, m, k, v[N], p[N], q[N];
vector<int> e[N];

bool dfs(int x, int lv, int a[])
{
	v[x] = lv;

	for(int to : e[x])
		if(!a[to] || (v[a[to]]<lv && dfs(a[to],lv,a)))
		{
			a[to] = x;
			return true;
		}

	return false;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<k; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
	}

	int res = 0;
	int level = 1;
	for(int i=1; i<=n; ++i)
		if(dfs(i, level++, p))
			++res;

	int plus = 0;
	for (int i=1; i<=n; ++i)
	{
		int cnt = 0;
		memcpy(q, p, sizeof(p));
		for (int j=0; j<2; ++j)
			if (dfs(i, level++, q))
				++cnt;
		plus = max(plus, cnt);
	}

	printf("%d\n", res+plus);
	return 0;
}