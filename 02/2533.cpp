#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1000010

using namespace std;

int n, d[N][2];
bool v[N];
vector<int> e[N], w[N];

void f(int x)
{
	v[x] = true;

	for(int to : e[x])
		if(!v[to])
		{
			w[x].push_back(to);
			f(to);
		}
}

int g(int x, int m)
{
	if(d[x][m] == -1)
	{
		int sum = 1;

		for(int to : w[x])
			sum += g(to, false);
		d[x][m] = sum;

		if(!m)
		{
			sum = 0;
			for(int to : w[x])
				sum += g(to, true);
			d[x][m] = min(d[x][m], sum);
		}
	}
	return d[x][m];
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n-1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	f(0);
	memset(d, -1, sizeof(d));

	printf("%d\n", g(0, false));
	return 0;
}
