#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#define N 1000

using namespace std;

int n, m;
int dfsn[N*2], scc[N*2], dfscnt, scc_num;
bool finish[N*2];
vector<int> e[N*2];
stack<int> s;

int dfs(int x)
{
	dfsn[x] = ++dfscnt;
	s.push(x);

	int top = dfsn[x];
	for (int to : e[x])
	{
		if (dfsn[to] == 0)
			top = min(top, dfs(to));
		else if (!finish[to])
			top = min(top, dfsn[to]);
	}

	if (top == dfsn[x])
	{
		int v = -1;
		while (v != x)
		{
			v = s.top();
			s.pop();
			finish[v] = true;
			scc[v] = scc_num;
		}
		++scc_num;
	}
	return top;
}

int main()
{
	while (true)
	{
		int n, m;
		if (scanf("%d %d", &n, &m) != 2)
			break;

		dfscnt = 0;
		scc_num = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(finish, 0, sizeof(finish));
		for (int i=0; i<n*2; ++i)
			e[i].clear();

		e[1].push_back(0);
		for (int i=0; i<m; ++i)
		{
			int a, b;
			int not_a, not_b;

			scanf("%d %d", &a, &b);
			a = a>0? (a-1)*2 : -a*2-1;
			b = b>0? (b-1)*2 : -b*2-1;
			not_a = a ^ 1;
			not_b = b ^ 1;

			e[not_a].push_back(b);
			e[not_b].push_back(a);
		}

		for (int i=0; i<n*2; ++i)
			if (dfsn[i] == 0)
				dfs(i);

		bool flag = true;
		for (int i=0; i<n; ++i)
			if (scc[i*2] == scc[i*2+1])
				flag = false;
		printf("%s\n", flag? "yes" : "no");
	}

	return 0;
}