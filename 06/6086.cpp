#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

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

int char_to_num(char c)
{
	return c<'a'? c-'A' : c-'a'+26;
}

int main()
{
	maximum_flow mf(52, 0, 25);

	int n;
	scanf("%d", &n);
	while(n--)
	{
		char a, b;
		int x, y, z;
		scanf(" %c %c %d", &a, &b, &z);
		x = char_to_num(a);
		y = char_to_num(b);
		mf.add_edge(x, y, z);
		mf.add_edge(y, x, z);
	}

	printf("%d", mf.flow());
	return 0;
}
