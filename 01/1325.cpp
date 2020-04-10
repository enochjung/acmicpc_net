#include <cstdio>
#include <vector>

using namespace std;

int n, m;
int v[10010], val;
vector<int> e[10010], res;

int f(int x, int lv)
{
	int sum = 1;

	v[x] = lv;
	for(int to : e[x])
		if(v[to] != lv)
			sum += f(to, lv);

	return sum;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		e[b].push_back(a);
	}

	for(int i=1; i<=n; i++)
	{
		int ret = f(i, i);
		if(val < ret)
		{
			res.clear();
			res.push_back(i);
			val = ret;
		}
		else if(val == ret)
			res.push_back(i);
	}

	for(int v : res)
		printf("%d ", v);
	return 0;
}
