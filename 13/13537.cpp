#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100010
#define M 100010

using namespace std;

struct st
{
	int i, j, v, t, n;
	bool operator<(const st &hs) const
	{
		return v!=hs.v? v>hs.v : t>hs.t;
	}
};

int n, m;
vector<st> q;
int t[N];

void update(int idx, int val)
{
	while(idx <= n)
	{
		t[idx] += val;
		idx += idx&-idx;
	}
}

int get(int idx)
{
	int sum = 0;
	while(idx)
	{
		sum += t[idx];
		idx -= idx&-idx;
	}
	return sum;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		q.push_back({i+1, 0, v, 1, 0});
	}
	scanf("%d", &m);
	for(int i=0; i<m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		q.push_back({a, b, c, 2, i});
	}

	sort(q.begin(), q.end());

	int res[M];
	for(st now : q)
	{
		if(now.t == 1)
			update(now.i, 1);
		else
			res[now.n] = get(now.j)-get(now.i-1);
	}

	for(int i=0; i<m; ++i)
		printf("%d\n", res[i]);
	return 0;
}
