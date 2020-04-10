#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#define N 100010

using namespace std;

int t, n, m;
int d[N], sn, si[N];
bool finish[N];
stack<int> s;
vector<int> e[N];

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

int main()
{
	for(scanf("%d",&t); t--;)
	{
		sn = 0;
		memset(d, 0, sizeof(d));
		memset(finish, 0, sizeof(finish));

		scanf("%d %d", &n, &m);
		while(m--)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			--a, --b;
			e[a].push_back(b);
		}

		for(int i=0; i<n; ++i)
			if(d[i] == 0)
				f(i);

		bool res[N] = {};
		for(int i=0; i<n; ++i)
		{
			for(int to : e[i])
				if(si[i] != si[to])
					res[si[to]] = true;
			e[i].clear();
		}
		
		int ans = 0;
		for(int i=0; i<sn; ++i)
			if(!res[i])
				++ans;
		printf("%d\n", ans);
	}

	return 0;
}
