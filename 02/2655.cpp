#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define N 110

using namespace std;

struct st
{
	int i, b, h, w;
	bool operator<(const st &hs) const
	{
		return b!=hs.b? b>hs.b : w>hs.w;
	}
};

int n, d[N][N];
bool p[N][N];
st a[N];
stack<int> s;

int f(int x, int y)
{
	if(x == n)
		return 0;
	if(d[x][y] == -1)
	{
		d[x][y] = f(x+1, y);
		if(a[x].w <= a[y].w)
		{
			int ret = f(x+1,x)+a[x].h;
			if(d[x][y] < ret)
			{
				d[x][y] = ret;
				p[x][y] = true;
			}
		}
	}

	return d[x][y];
}

void g(int x, int y)
{
	if(x == n)
		return;
	if(p[x][y])
	{
		s.push(a[x].i);
		g(x+1, x);
	}
	else
		g(x+1, y);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int b, h, w;
		scanf("%d %d %d", &b, &h, &w);
		a[i] = {i+1, b, h, w};
	}
	a[n++] = {-1, 99999, 0, 99999};

	sort(a, a+n);

	memset(d, -1, sizeof(d));
	f(1, 0);
	g(1, 0);

	printf("%d\n", (int)s.size());
	for(; !s.empty(); s.pop())
		printf("%d\n", s.top());
	return 0;
}
