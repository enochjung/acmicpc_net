#include <cstdio>
#include <cstring>
#include <vector>
#define N 10001

using namespace std;

int n, d[N];
vector<pair<int,int>> e[N];

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
	scanf("%d", &n);
	while (--n)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}

	memset(d, -1, sizeof(d));
	int res = f(1, 0);
	memset(d, -1, sizeof(d));
	res = f(res, 0);

	printf("%d\n", d[res]);
	return 0;
}