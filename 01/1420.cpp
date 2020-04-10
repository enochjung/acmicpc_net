#include <cstdio>
#include <queue>
#include <vector>
#define N 110

using namespace std;

class maximum_flow
{
private:
	struct edge
	{
		int to, cap, rev;
		edge(int to, int cap) : to(to), cap(cap) {}
	};

	vector<vector<edge>> e;
	vector<bool> visited;
	vector<int> lv, work;

	int n, src, sink;

	bool bfs()
	{
		queue<int> q;
		lv.clear();
		lv.resize(n);

		lv[src] = 1;
		q.push(src);
		while(!q.empty())
		{
			int now = q.front();
			q.pop();

			for(auto p : e[now])
				if(!lv[p.to] && p.cap>0)
				{
					lv[p.to] = lv[now]+1;
					q.push(p.to);
				}
		}

		return lv[sink];
	}

	int dfs(int x, int f=0x7fffffff)
	{
		if(x == sink)
			return f;

		for(int &i=work[x]; i<(int)e[x].size(); ++i)
		{
			int to = e[x][i].to;
			int cap = e[x][i].cap;

			if(lv[x]+1==lv[to] && cap)
			{
				int ret = dfs(to, min(f, cap));
				if(ret)
				{
					e[x][i].cap -= ret;
					e[to][e[x][i].rev].cap += ret;
					return ret;
				}
			}
		}

		return 0;
	}

public:
	maximum_flow(int n, int src, int sink) : n(n), src(src), sink(sink)
	{
		e.resize(n);
		visited.resize(n);
	}

	void add_edge(int from, int to, int cap)
	{
		e[from].push_back({to, cap});
		e[to].push_back({from, 0});
		e[from].back().rev = e[to].size()-1;
		e[to].back().rev = e[from].size()-1;
	}

	int flow()
	{
		int ret = 0;

		while(bfs())
		{
			work.clear();
			work.resize(n);

			int val;
			while((val = dfs(src)))
				ret += val;
		}

		return ret;
	}
};

int n, m;
char s[N][N];
int kx, ky, hx, hy;
int dx[]={-1, 0, 1, 0}, dy[]={0, -1, 0, 1};

int idx(int i, int j, bool out)
{
	return (i*m+j)*2+out;
}

int abs(int x)
{
	return x>0? x : -x;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
	{
		scanf("%s", s[i]);
		for(int j=0; j<m; ++j)
		{
			if(s[i][j] == 'K')
			{
				kx = i;
				ky = j;
			}
			else if(s[i][j] == 'H')
			{
				hx = i;
				hy = j;
			}
		}
	}

	if(abs(kx-hx)+abs(ky-hy) == 1)
	{
		printf("-1");
		return 0;
	}
	
	maximum_flow mf(n*m*2, idx(kx,ky,true), idx(hx,hy,false));
	
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
		{
			if(s[i][j] != '#')
				mf.add_edge(idx(i,j,false), idx(i,j,true), 1);
			for(int w=0; w<4; ++w)
			{
				int ti = i+dx[w];
				int tj = j+dy[w];
				if(0<=ti && ti<n && 0<=tj && tj<m)
					mf.add_edge(idx(i,j,true), idx(ti,tj,false), 1);
			}
		}
	}

	printf("%d", mf.flow());
	return 0;
}
