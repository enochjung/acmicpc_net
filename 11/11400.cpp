#include <cstdio>
#include <algorithm>
#include <vector>
#define V 100001

using namespace std;

int v, e;
vector<int> l[V];
int d[V], num;
vector<pair<int,int>> res;

int f(int x, int parent)
{
	d[x] = ++num;

	int ret = d[x];
	for (int to : l[x])
	{
		if (to == parent)
			continue;
		if (d[to] == 0)
		{
			int val = f(to, x);
			if (val > d[x])
				res.push_back({x, to});
			ret = min(ret, val);
		}
		else
			ret = min(ret, d[to]);
	}
	
	return ret;
}

int main()
{
	scanf("%d %d", &v, &e);
	while (e--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		l[a].push_back(b);
		l[b].push_back(a);
	}

	f(1, 0);
	
	for (auto &p : res)
		if (p.first > p.second)
			swap(p.first, p.second);
	sort(res.begin(), res.end());

	printf("%d\n", res.size());
	for (auto p : res)
		printf("%d %d\n", p.first, p.second);
	return 0;
}