#include <cstdio>
#include <algorithm>
#include <vector>
#define N 2010

using namespace std;

int n, m;
int q[N], v[N];
bool c[N];
vector<int> e[N];

bool f(int x, int lv)
{
	v[x] = lv;

	for(int y : e[x])
		if(q[y]==0 || (v[q[y]]<lv && f(q[y],lv)))
		{
			q[y] = x;
			return true;
		}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
	{
		int a;
		char b;
		scanf("%d %c", &a, &b);
		c[a] = b=='c'? 1 : 0;
	}
	for(int i=0; i<m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if(c[a])
			e[a].push_back(b);
		else
			e[b].push_back(a);
	}

	int res = 0;
	for(int i=1; i<=n; ++i)
		if(c[i] && f(i,i))
			++res;
	printf("%d", n-res);
	return 0;
}
