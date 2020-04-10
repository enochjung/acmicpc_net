#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#define N 20010

using namespace std;

int n, m;
int dfsn[N], scc[N], scc_num;
bool finish[N];
stack<int> s;
vector<int> e[N];
 
int dfs(int x)
{
	static int cnt = 0;
	dfsn[x] = ++cnt;
	s.push(x);

	int top = dfsn[x];
	for(int to : e[x])
	{
		if(dfsn[to] == 0)
			top = min(top, dfs(to));
		else if(!finish[to])
			top = min(top, dfsn[to]);
	}

	if(top == dfsn[x])
	{
		int v = -1;

		while(v != x)
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
	scanf("%d %d", &n, &m);
	n *= 2;
	for(int i=0; i<m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a = a>0? a-1 : n+a;
		b = b>0? b-1 : n+b;
		e[n-1-a].push_back(b);
		e[n-1-b].push_back(a);
	}

	for(int i=0; i<n; ++i)
		if(dfsn[i] == 0)
			dfs(i);
 
	for(int i=0; i<n/2; ++i)
		if(scc[i] == scc[n-1-i])
		{
			printf("0");
			return 0;
		}
	printf("1");
	return 0;
}
