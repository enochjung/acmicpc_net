#include <cstdio>
#include <algorithm>
#include <vector>
#define V 10001

using namespace std;

int v, e;
vector<int> l[V];
int d[V], num;
bool res[V];

int f(int x, bool root)
{
	d[x] = ++num;

	int ret = d[x];
	int child = 0;
	for (int to : l[x])
	{
		if (d[to] == 0)
		{
			int val = f(to, false);
			if (val == d[x])
				res[x] = true;
			ret = min(ret, val);
			++child;
		}
		else
			ret = min(ret, d[to]);
	}
	if (root)
		res[x] = child>1;
	
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

	for (int i=1; i<=v; ++i)
		if (d[i] == 0)
			f(i, true);

	vector<int> p;
	for (int i=1; i<=v; ++i)
		if (res[i])
			p.push_back(i);
		
	printf("%d\n", p.size());
	for (int n : p)
		printf("%d ", n);
	return 0;
}