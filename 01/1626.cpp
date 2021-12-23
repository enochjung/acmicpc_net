#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#define V 50000
#define LOGV 16
#define E 200000

struct edge
{
	int a, b, w;
};

struct way
{
	int to, ma, mb;
};

int v, e;
edge edges[E];
int mst_value;
bool in_mst[E];
std::vector<way> two_way[V];
way mst_parent[V][LOGV];
int mst_depth[V];

void error()
{
	printf("-1\n");
	exit(0);
}

void input()
{
	scanf("%d %d", &v, &e);
	for(int i=0; i<e; ++i)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		edges[i] = {a-1, b-1, w};
	}
	
	std::sort(edges, edges+e, [](edge &i, edge &j){return i.w<j.w;});
}

void make_mst()
{
	int g[V];
	std::function<int(int)> parent = [&](int x)
	{
		return x==g[x]? x : g[x]=parent(g[x]);
	};
	auto merge = [&](int a, int b) -> void
	{
		int pa = parent(a);
		int pb = parent(b);

		if (pa > pb)
			g[pa] = pb;
		else
			g[pb] = pa;
	};

	for(int i=0; i<v; ++i)
		g[i] = i;

	int cnt = 0;
	for(int i=0; i<e; ++i)
	{
		int a = edges[i].a;
		int b = edges[i].b;

		if (parent(a) != parent(b))
		{
			++cnt;
			merge(a, b);
			mst_value += edges[i].w;
			in_mst[i] = true;
			two_way[a].push_back({b, edges[i].w, -1});
			two_way[b].push_back({a, edges[i].w, -1});
		}
		if (cnt == v-1)
			break;
	}
	if (cnt < v-1)
		error();

	bool visited[V] = {};
	memset(mst_parent, -1, sizeof(mst_parent));
	mst_parent[0][0] = {-1, -1, -1};
	mst_depth[0] = 0;
	std::function<void(int)> make_tree = [&](int x)
	{
		visited[x] = true;

		for (way w : two_way[x])
		{
			int to = w.to;
			if (!visited[to])
			{
				mst_parent[to][0] = {x, w.ma, -1};
				mst_depth[to] = mst_depth[x] + 1;
				make_tree(to);
			}
		}
	};
	make_tree(0);
}

void make_lca()
{
	for (int j=0; j<LOGV-1; ++j)
		for (int i=0; i<v; ++i)
			if (mst_parent[i][j].to != -1)
			{
				int p = mst_parent[i][j].to;
				mst_parent[i][j+1].to = mst_parent[p][j].to;

				int a = mst_parent[i][j].ma;
				int b = mst_parent[i][j].mb;
				int c = mst_parent[p][j].ma;
				int d = mst_parent[p][j].mb;

				if (a > c)
				{
					mst_parent[i][j+1].ma = a;
					mst_parent[i][j+1].mb = std::max(b, c);
				}
				else if (a < c)
				{
					mst_parent[i][j+1].ma = c;
					mst_parent[i][j+1].mb = std::max(a, d);
				}
				else
				{
					mst_parent[i][j+1].ma = a;
					mst_parent[i][j+1].mb = std::max(b, d);
				}
			}
}

void calculate()
{
	int res = -1;

	auto get_way = [&](int a, int b) -> way
	{
		if (mst_depth[a] < mst_depth[b])
			std::swap(a, b);
		int diff = mst_depth[a] - mst_depth[b];
		int ma=-1, mb=-1;

		auto update = [&](int nma, int nmb) -> void
		{
			if (ma > nma)
				mb = std::max(mb, nma);
			else if (ma == nma)
				mb = std::max(mb, nmb);
			else if (ma == -1)
			{
				ma = nma;
				mb = nmb;
			}
			else
			{
				mb = std::max(ma, nmb);
				ma = nma;
			}
		};
 
		for (int j=0; diff; ++j,diff>>=1)
			if (diff%2 == 1)
			{
				update(mst_parent[a][j].ma, mst_parent[a][j].mb);
				a = mst_parent[a][j].to;
			}
 
		if (a != b)
		{
			for (int j=LOGV-1; j>=0; --j)
				if(mst_parent[a][j].to!=-1 && mst_parent[a][j].to!=mst_parent[b][j].to)
				{
					update(mst_parent[a][j].ma, mst_parent[a][j].mb);
					update(mst_parent[b][j].ma, mst_parent[b][j].mb);
					a = mst_parent[a][j].to;
					b = mst_parent[b][j].to;
				}
			update(mst_parent[a][0].ma, mst_parent[a][0].mb);
			update(mst_parent[b][0].ma, mst_parent[b][0].mb);
		}
		return {-1, ma, mb};
	};

	for (int i=0; i<e; ++i)
		if (!in_mst[i])
		{
			way max_way = get_way(edges[i].a, edges[i].b);
			int w = edges[i].w;
			int ma = max_way.ma;
			int mb = max_way.mb;

			if (w > ma)
			{
				int val = mst_value-ma+w;
				if (res==-1 || res>val)
					res = val;
			}
			else if (mb >= 0)
			{
				int val = mst_value-mb+w;
				if (res==-1 || res>val)
					res = val;
			}
		}
	printf("%d\n", res);
}

int main()
{
	input();
	make_mst();
	make_lca();
	calculate();
	return 0;
}
