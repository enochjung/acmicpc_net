#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#define V 10010

using namespace std;

int v, e, dfsn[V];
bool finish[V];
stack<int> s;
vector<int> edge[V];
vector<vector<int>> scc;
 
int dfs(int x)
{
	static int cnt = 0;
	dfsn[x] = ++cnt;
	s.push(x);

	int top = dfsn[x];
	for(int to : edge[x])
	{
		if(dfsn[to] == 0)
			top = min(top, dfs(to));
		else if(!finish[to])
			top = min(top, dfsn[to]);
	}

	if(top == dfsn[x])
	{
		vector<int> now;
		int v = -1;

		while(v != x)
		{
			v = s.top();
			s.pop();
			finish[v] = true;
			now.push_back(v);
		}

		scc.push_back(now);
	}

	return top;
}
 
int main()
{
	scanf("%d %d", &v, &e);
	for(int i=0; i<e; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		edge[a].push_back(b);
	}

	for(int i=0; i<v; ++i)
		if(dfsn[i] == 0)
			dfs(i);
	
	for(int i=0; i<(int)scc.size(); ++i)
		sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end());

	printf("%d\n", (int)scc.size());
	for(auto& now : scc)
	{
		for(int val : now)
			printf("%d ", val+1);
		printf("-1\n");
	}
	return 0;
}
