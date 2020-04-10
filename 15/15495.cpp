#include <cstdio>
#include <queue>
#include <set>
#define N 100010
#define M 100010
#define K 100010

using namespace std;

int m, k, a[M];
queue<int> q;
set<int> x[K], y[K], t[N], res;
bool visited[K];

void insert(int val)
{
	if(res.find(val) != res.end())
		return;

	res.insert(val);

	for(int i : t[val])
	{
		x[i].erase(val);
		if(x[i].empty() && !visited[i])
		{
			q.push(i);
			visited[i] = true;
		}
	}
}

int main()
{
	scanf("%*d %d", &m);
	for(int i=0; i<m; ++i)
		scanf("%d", a+i);
	scanf("%d", &k);
	for(int i=0; i<k; ++i)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		while(l--)
		{
			int v;
			scanf("%d", &v);
			x[i].insert(v);
			t[v].insert(i);
		}
		while(r--)
		{
			int v;
			scanf("%d", &v);
			y[i].insert(v);
		}
	}

	for(int i=0; i<m; ++i)
		insert(a[i]);

	while(!q.empty())
	{
		int i = q.front();
		q.pop();

		for(int v : y[i])
			insert(v);
	}

	printf("%d\n", (int)res.size());
	for(int v : res)
		printf("%d ", v);
	return 0;
}
