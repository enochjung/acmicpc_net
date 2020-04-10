#include <cstdio>
#include <algorithm>
#include <vector>
#define V 50010
#define E 200010

using std::sort;
using std::vector;

struct edge
{
	int p, q, w;
};

int v, e;
vector<edge> l;
bool mst[E];

void make_mst()
{
	int g[V];
	
	for(int i=0; i<v; ++i)
		g[i] = i;

	for(int i=0; i<e; ++i)
	{
		auto parent = [](int x)
		{
			return x==g[x]? x : parent(g[x]);
		};
		
	}
}

int main()
{
	scanf("%d %d", &v, &e);
	for(int i=0; i<e; ++i)
	{
		int p, q, w;
		scanf("%d %d %d", &p, &q, &w);
		l.push_back({p-1, q-1, w});
	}
	
	sort(l.begin(), l.end(), [](edge &i, edge &j){return i.w<j.w;});
	return 0;
}
