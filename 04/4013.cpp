#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#define N 500010

using namespace std;

int n, m, st, p;
int d[N], si[N], sn;
int gc[N], gd[N];
bool finish[N], visited[N], rest[N];
stack<int> s;
vector<int> e[N];
vector<int> ge[N];

int f(int x)
{
	static int cnt = 0;
	d[x] = ++cnt;
	s.push(x);
	
	int top = d[x];
	for(int to : e[x])
	{
		if(d[to] == 0)
			top = min(top, f(to));
		else if(!finish[to])
			top = min(top, d[to]);
	}

	if(top == d[x])
	{
		int v = -1;
		while(v != x)
		{
			v = s.top();
			s.pop();
			si[v] = sn;
			finish[v] = true;
		}
		++sn;
	}

	return top;
}

int g(int x)
{
	if(!visited[x])
	{
		visited[x] = true;

		if(x == st)
			gd[x] = gc[x];
		else
		{
			int mc = -1;
			for(int to : ge[x])
				mc = max(mc, g(to));
		
			if(mc == -1)
				gd[x] = -1;
			else
				gd[x] = mc+gc[x];
		}
	}

	return gd[x];
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[a-1].push_back(b-1);
	}
	for(int i=0; i<n; ++i)
		if(d[i] == 0)
			f(i);
	for(int i=0; i<n; ++i)
	{
		int c;
		scanf("%d", &c);
		gc[si[i]] += c;
	}
	for(int i=0; i<n; ++i)
		for(int to : e[i])
			if(si[i] != si[to])
				ge[si[to]].push_back(si[i]);
	scanf("%d %d", &st, &p);
	st = si[st-1];
	while(p--)
	{
		int v;
		scanf("%d", &v);
		rest[si[v-1]] = true;
	}

	int res = 0;
	for(int i=0; i<sn; ++i)
		if(rest[i])
			res = max(res, g(i));
	printf("%d", res);
	return 0;
}
