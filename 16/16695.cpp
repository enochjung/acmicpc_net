#include <cstdio>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#define N 100010

using namespace std;
typedef pair<int,int> pii;

struct edge
{
	int a, b, s, e;
};

int n, q;
vector<pii> vq;
vector<int> res;
int p[N], s[N];

int group(int x)
{
	return x==p[x]? x : group(p[x]);
}

void combine(int i, int j)
{
	if(s[i] > s[j])
	{
		p[j] = i;
		s[i] += s[j];
	}
	else
	{
		p[i] = j;
		s[j] += s[i];
	}
}

void split(int i, int j)
{
	if(s[i] > s[j])
	{
		p[j] = j;
		s[i] -= s[j];
	}
	else
	{
		p[i] = i;
		s[j] -= s[i];
	}
}

void f(int s, int e, vector<edge> &ve, int danger)
{
	int m = (s+e)/2;

	vector<edge> pve, qve;
	stack<pii> restore;
	while(!ve.empty())
	{
		edge &now = ve.back();

		if(now.s<=s && e<=now.e)
		{
			int i = group(now.a);
			int j = group(now.b);

			if(i != j)
			{
				combine(i, j);
				restore.push({i, j});
			}
		}
		else
		{
			if((now.s<=s && s<now.e) || (s<now.s && now.s<m))
				pve.push_back(now);
			if((now.s<=m && m<now.e) || (m<now.s && now.s<e))
				qve.push_back(now);
		}

		ve.pop_back();
	}

	if(s+1 == e)
	{
		if(res[s]==99 && group(vq[s].first)==group(vq[s].second))
			res[s] = danger;
	}
	else
	{
		f(s, m, pve, danger);
		f(m, e, qve, danger);
	}

	while(!restore.empty())
	{
		auto &now = restore.top();
		split(now.first, now.second);
		restore.pop();
	}
}

int main()
{
	scanf("%d %d", &n, &q);

	vector<edge> ve[10];
	map<pii,pii> m;
	int cnt = 0;
	while(q--)
	{
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if(x > y)
			swap(x, y);

		if(t == 0)
		{
			int v;
			scanf("%d", &v);
			m.insert({{x,y}, {cnt,v}});
		}
		else if(t == 1)
		{
			auto iter = m.find(pii(x, y));
			for(int i=iter->second.second; i<10; ++i)
				ve[i].push_back({x, y, iter->second.first, cnt});
			m.erase(iter);
		}
		else
		{
			vq.push_back({x, y});
			++cnt;
		}
	}
	for(auto v : m)
		for(int i=v.second.second; i<10; ++i)
			ve[i].push_back({v.first.first, v.first.second, v.second.first, cnt});

	res.resize(cnt, 99);
	for(int i=0; i<n; ++i)
	{
		p[i] = i;
		s[i] = 1;
	}
	for(int i=0; i<10; ++i)
		f(0, cnt, ve[i], i);

	for(int v : res)
		printf("%d\n", v==99? -1 : v);

	return 0;
}
