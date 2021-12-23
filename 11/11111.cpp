#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define N 51
#define M (N*N)
#define INF 0x7fffffff

using namespace std;

class mcmf
{
private:
	struct edge
	{
		int to, cap, cost, rev;
		edge(int to, int cap, int cost) : to(to), cap(cap), cost(cost) {}
	};

	int n, src, sink;
	vector<vector<edge>> e;
	vector<int> d;
	vector<pair<int,int>> p;

public:
	mcmf(int n, int src, int sink) : n(n), src(src), sink(sink)
	{
		e.resize(n);
		d.resize(n);
		p.resize(n);
	}

	void add_edge(int from, int to, int cap, int cost)
	{
		e[from].push_back({to, cap, cost});
		e[to].push_back({from, 0, -cost});
		e[from].back().rev = e[to].size()-1;
		e[to].back().rev = e[from].size()-1;
	}

	pair<int,int> flow()
	{
		int flow = 0;
		int cost = 0;
		vector<bool> iq;
		iq.resize(n);

		while(1)
		{
			queue<int> q;

			fill(d.begin(), d.end(), INF);
			fill(p.begin(), p.end(), make_pair(-1, -1));

			d[src] = 0;
			q.push(src);
			iq[src] = true;
			while(!q.empty())
			{
				int now = q.front();
				q.pop();
				iq[now] = false;

				for(int i=0; i<(int)e[now].size(); ++i)
				{
					auto &t = e[now][i];
					if(t.cap && d[t.to]>d[now]+t.cost)
					{
						d[t.to] = d[now]+t.cost;
						p[t.to] = {now, i};
						if(!iq[t.to])
						{
							q.push(t.to);
							iq[t.to] = true;
						}
					}
				}
			}
			if(p[sink].first == -1)
				break;

			int f = INF;
			for(int i=sink; i!=src; i=p[i].first)
				f = min(f, e[p[i].first][p[i].second].cap);
			flow += f;

			for(int i=sink; i!=src; i=p[i].first)
			{
				auto &t = e[p[i].first][p[i].second];
				cost += f*t.cost;
				t.cap -= f;
				e[i][t.rev].cap += f;
			}
		}

		return {flow, cost};
	}
};

int n, m;
char a[N][N];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int p[5][5] =
{
	{10, 8, 7, 5, 1},
	{ 8, 6, 4, 3, 1},
	{ 7, 4, 3, 2, 1},
	{ 5, 3, 2, 2, 1},
	{ 1, 1, 1, 1, 0}
};

int price(char x, char y)
{
	int xx = x=='F'? 4 : x-'A';
	int yy = y=='F'? 4 : y-'A';
	return p[xx][yy];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		scanf("%s", a[i]);

	mcmf mf(n*m+2, n*m, n*m+1);

	for (int i=0; i<n; ++i)
		for (int j=i&1; j<m; j+=2)
		{
			mf.add_edge(n*m, i*m+j, 1, 0);
			mf.add_edge(i*m+j, n*m+1, 1, 0);

			for (int w=0; w<4; ++w)
			{
				int ti = i+dx[w];
				int tj = j+dy[w];
				if (0<=ti && ti<n && 0<=tj && tj<m)
					mf.add_edge(i*m+j, ti*m+tj, 1, -price(a[i][j], a[ti][tj]));
			}
		}
	for (int i=0; i<n; ++i)
		for (int j=1-(i&1); j<m; j+=2)
			mf.add_edge(i*m+j, n*m+1, 1, 0);

	printf("%d\n", -mf.flow().second);
	return 0;
}