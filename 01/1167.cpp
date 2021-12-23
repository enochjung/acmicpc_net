#include <cstdio>
#include <cstring>
#include <vector>
#define V 100001

using namespace std;

int v, d[V];
vector<pair<int,int>> e[V];

int f(int x, int t)
{
	int res = x;
	d[x] = t;

	for (auto to : e[x])
		if (d[to.first] == -1)
		{
			int ret = f(to.first, t+to.second);
			if (d[res] < d[ret])
				res = ret;
		}

	return res;
}

int main()
{
	scanf("%d", &v);
	while (v--)
	{
		int a, b, t;
		scanf("%d", &a);
		while (scanf("%d",&b), b!=-1)
		{
			scanf("%d", &t);
			e[a].push_back({b, t});
		}
	}

	memset(d, -1, sizeof(d));
	int res = f(1, 0);
	memset(d, -1, sizeof(d));
	res = f(res, 0);

	printf("%d\n", d[res]);
	return 0;
}