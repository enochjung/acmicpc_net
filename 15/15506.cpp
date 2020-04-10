#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
#define INF 8888888888888888888LL

using namespace std;

struct operation
{
	int t;
    long long h;
};

struct answer
{
	bool p;
	int t, l, r;
	bool operator<(const answer &i) const
	{
		return t < i.t;
	}
};

int n, m, k;
vector<operation> p[N], o[N];
vector<answer> ans;

long long treee[(1<<21)+10];
class my_segment
{
private:
	int start;

	inline int left(int x)
	{
		return x<<1;
	}
	
	inline int right(int x)
	{
		return (x<<1)+1;
	}

public:
	my_segment(int size)
	{
		for(start=1; start<size; start<<=1);
		for(int i=1; i<=start*2; ++i)
			treee[i] = INF;
	}

	void update(int x, long long value)
	{
		x += start;
		treee[x] = value;
		while(x > 1)
		{
			x >>= 1;
			long long val = min(treee[left(x)], treee[right(x)]);
			if(treee[x] == val)
				break;
			treee[x] = val;
		}
	}

	int find(int t, long long h, int x=1, int s=0, int e=-1)
	{
		if(e == -1)
			e = start;
		if(e<=t+1 || treee[x]>=h)
			return -1;
		if(s == e-1)
			return s;

		int mid = (s+e)/2;
		int val = find(t, h, left(x), s, mid);
		if(val != -1)
			return val;
		return find(t, h, right(x), mid, e);
	}
};

class my_binary
{
private:
	int size;
	int tree[N];

public:
	my_binary(int size)
	{
		this->size = size;
		memset(tree, 0, sizeof(tree));
	}

	void update(int x, int value)
	{
		for(; x<=size; x+=(x&-x))
			tree[x] += value;
	}
	
	int find(int x)
	{
		int sum = 0;
		for(; x; x-=(x&-x))
			sum += tree[x];
		return sum;
	}
};

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<m; ++i)
	{
		int c, t, x, l, r, h;
		scanf("%d", &c);
		switch(c)
		{
		case 1:
			scanf("%d %d %d", &t, &x, &h);
			p[x].push_back({i, h-1LL*k*t});
			ans.push_back({false, i, x, 1});
			break;

		case 2:
			scanf("%d %d %d %d", &t, &l, &r, &h);
			o[l].push_back({i, h-1LL*k*t});
			o[r+1].push_back({i, INF});
			break;

		case 3:
			scanf("%*d %d %d", &l, &r);
			ans.push_back({true, i, l, r});
			break;
		}
	}
	o[1].push_back({m++, -INF});

	my_segment s(m);
	for(int i=1; i<=n; ++i)
	{
		for(auto op : o[i])
			s.update(op.t, op.h);
		for(auto pl : p[i])
			ans.push_back({false, s.find(pl.t,pl.h), i, -1});

	}

	sort(ans.begin(), ans.end());

	my_binary b(n);
	for(auto i : ans)
	{
		if(i.p)
			printf("%d\n", b.find(i.r)-b.find(i.l-1));
		else
			b.update(i.l, i.r);
	}

	return 0;
}
