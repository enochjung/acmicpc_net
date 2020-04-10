#include <cstdio>
#include <algorithm>
#include <vector>
#define N 110

using namespace std;

int n;
bool v[N];
vector<int> e[N];
vector<int> t[2];

void f(int x, bool b)
{
	v[x] = true;
	t[b].push_back(x);

	for(int to : e[x])
		if(!v[to])
			f(to, !b);
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		int s, w;
		scanf("%d", &s);
		while(s--)
		{
			scanf("%d", &w);
			e[i].push_back(w);
		}
	}

	for(int i=1; i<=n; ++i)
		if(!v[i])
			f(i, true);

	for(int i=0; i<2; ++i)
	{
		sort(t[i].begin(), t[i].end());
		printf("%d\n", (int)t[i].size());
		for(int j : t[i])
			printf("%d ", j);
		printf("\n");
	}
}
