#include <cstdio>
#include <vector>
#define N 51

using namespace std;

int n, m;
int g[N];
vector<int> v[N];

int group(int x)
{
	return x == g[x]? x : g[x]=group(g[x]);
}

void merge(int a, int b)
{
	int ga = group(a);
	int gb = group(b);

	if (ga < gb)
		g[gb] = ga;
	else
		g[ga] = gb;
}

int main()
{
	int num;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		g[i] = i;
	scanf("%d", &num);
	while (num--)
	{
		int val;
		scanf("%d", &val);
		g[val] = 0;
	}
	for (int i=0; i<m; ++i)
	{
		scanf("%d", &num);
		while (num--)
		{
			int val;
			scanf("%d", &val);
			v[i].push_back(val);
		}
	}

	for (int i=0; i<m; ++i)
		if (v[i].size() > 1)
		{
			int a = v[i][0];
			for (int j=1; j<v[i].size(); ++j)
				merge(a, v[i][j]);
		}

	int res = 0;
	for (int i=0; i<m; ++i)
		if (group(v[i][0]) != 0)
			++res;

	printf("%d\n", res);
	return 0;
}