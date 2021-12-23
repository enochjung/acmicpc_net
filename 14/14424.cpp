#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define N 201
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

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
#define zero_stl(v, sz) fill(v.begin(), v.begin()+(sz), 0)
using namespace std;

template<const int MAX_V, typename flow_t, typename cost_t, flow_t FLOW_INF, cost_t COST_INF, const int SCALE = 16>
class CostScalingMCMF {
public:
    struct Edge{
        int v; flow_t c; cost_t d; int r; // next, residual capacity, weight, reverse edge
        Edge() = default;
        Edge(int v, flow_t c, cost_t d, int r) : v(v), c(c), d(d), r(r) {}
    };
    CostScalingMCMF(){
        negativeSelfLoop = 0;
        static_assert(numeric_limits<flow_t>::is_signed, "flow_t must be signed");
        static_assert(numeric_limits<cost_t>::is_signed, "cost_t must be signed");
        static_assert(SCALE >= 2, "scaling factor must be at least 2");
    }
    void clear(){
        negativeSelfLoop = 0;
        for(int i=0; i<MAX_V; i++) g[i].clear();
    }
    void addEdge(int s, int e, flow_t cap, cost_t dst){
        if(s == e){
            if(dst < 0) negativeSelfLoop += cap * dst;
            return;
        }
        g[s].emplace_back(e, cap, dst, int(g[e].size()));
        g[e].emplace_back(s, 0, -dst, int(g[s].size())-1);
    }
    flow_t getMaxFlow(int V, int S, int T){
        auto BFS = [&](){
            zero_stl(level, V);
            queue<int> q; q.push(S); level[S] = 1;
            while(q.size()){
                int v = q.front(); q.pop();
                for(const auto &e : g[v]) if(!level[e.v] && e.c) q.push(e.v), level[e.v] = level[v] + 1;
            }
            return level[T];
        };
        function<flow_t(int,flow_t)> DFS = [&](int v, flow_t fl){
            if(v == T || fl == 0) return fl;
            for(int &i=ptr[v]; i<g[v].size(); i++){
                Edge &e = g[v][i];
                if(level[e.v] != level[v] + 1 || !e.c) continue;
                flow_t delta = DFS(e.v, min(fl, e.c));
                if(delta){
                    e.c -= delta;
                    g[e.v][e.r].c += delta;
                    return delta;
                }
            }
            return flow_t(0);
        };

        flow_t maxFlow = 0, tmp = 0;
        while(BFS()){
            zero_stl(ptr, V);
            while((tmp = DFS(S, FLOW_INF))) maxFlow += tmp;
        }
        return maxFlow;
    }
    pair<flow_t, cost_t> run(int V, int S, int T){
        flow_t maxFlow = 0;
        cost_t minCost = 0, eps = 0;

        auto active_ins = [&](int v) { active_stk[active_top++] = v; };
        auto active_del = [&]() { return active_stk[--active_top]; };
        auto c_pi = [&](int v, const Edge &e) { return e.d + pi[v] - pi[e.v]; };
        auto push = [&](int v, Edge &e, flow_t delta, bool pushStack) {
            delta = min(delta, e.c);
            e.c -= delta; g[e.v][e.r].c += delta;
            excess[v] -= delta; excess[e.v] += delta;
            if(pushStack && 0 < excess[e.v] && excess[e.v] <= delta) active_ins(e.v);
        };
        auto relabel = [&](int v, cost_t delta) {
            pi[v] -= delta + eps;
        };
        auto discharge = [&](int v){
            cost_t delta = COST_INF;
            for(auto &e : g[v]){
                if(e.c <= 0) continue;
                cost_t reduced = c_pi(v, e);
                if(reduced < 0){
                    push(v, e, excess[v], true);
                    if(excess[v] == 0) return;
                }
                else delta = min(delta, reduced);
            }
            relabel(v, delta);
            active_ins(v);
        };

        zero_stl(pi, V);
        zero_stl(excess, V);
        for(int v=0; v<V; v++) for(auto &e : g[v]) minCost += e.c * e.d, e.d *= V+1, eps = max(eps, abs(e.d));
        maxFlow = getMaxFlow(V, S, T);
        while(eps > 1){
            eps /= SCALE; if(eps < 1) eps = 1;
            active_top = 0;
            for(int v=0; v<V; v++) for(auto &e : g[v]) if(e.c > 0 && c_pi(v, e) < 0) push(v, e, e.c, false);
            for(int v=0; v<V; v++) if(excess[v] > 0) active_ins(v);
            while(active_top > 0) discharge(active_del());
        }
        for(int v=0; v<V; v++) for(auto &e : g[v]) e.d /= V+1, minCost -= e.c * e.d;
        minCost = minCost / 2 + negativeSelfLoop;
        return {maxFlow, minCost};
    }

private:
    vector<Edge> g[MAX_V];
    cost_t negativeSelfLoop;
    array<flow_t, MAX_V> excess;
    array<cost_t, MAX_V> pi;
    array<int, MAX_V> active_stk;
    int active_top;

    array<int, MAX_V> level, ptr;
};

CostScalingMCMF<514, int, int, 0x3f3f3f3f, 0x3f3f3f3f> flow;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int S = n + m, T = n + m + 1;
    for(int i=0; i<n; i++) flow.addEdge(S, i, 1, 0);
    for(int i=0; i<m; i++) flow.addEdge(n+i, T, 1, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int t; cin >> t;
            flow.addEdge(i, n+j, 1, -t);
        }
    }
    cout << -flow.run(T+1, S, T).second;
}