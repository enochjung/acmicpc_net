#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#define N 100010

using namespace std;

int n, m, dfsn[N], sn[N], sc;
bool finished[N];
stack<int> s;
vector<int> edge[N];

int dfs(int x)
{
	static int cnt = 0;

	dfsn[x] = ++cnt;
	s.push(x);

	int res = dfsn[x];
	for(int to : edge[x])
	{
		if(!dfsn[to])
			res = min(res, dfs(to));
		else if(!finished[to])
			res = min(res, dfsn[to]);
	}

	if(res == dfsn[x])
	{
		while(1)
		{
			int t = s.top();
			s.pop();

			sn[t] = sc;
			finished[t] = true;
			if(t == x)
				break;
		}
		++sc;
	}

	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
	}

	for(int i=0; i<n; ++i)
		if(!dfsn[i])
			dfs(i);

	int res = 0;
	bool in[N] = {};
	for(int i=0; i<n; ++i)
		for(int to : edge[i])
			if(sn[i] != sn[to])
				in[sn[to]] = true;

	for(int i=0; i<sc; i++)
		if(!in[i])
			++res;
	printf("%d", res);

	return 0;
}
