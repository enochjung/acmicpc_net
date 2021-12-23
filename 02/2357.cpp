#include <cstdio>
#include <climits>
#include <algorithm>
#define T (1<<17)
#define TT (1<<18)

using namespace std;

int n, m;
pair<int,int> t[TT];

void update(int idx, int val)
{
	for (idx+=T-1; idx>=1; idx>>=1)
	{
		t[idx].first = min(t[idx].first, val);
		t[idx].second = max(t[idx].second, val);
	}
}

pair<int,int> get(int idx, int s, int e, int p, int q)
{
	if (s<=p && q<=e)
		return t[idx];
	if (q<=s || e<=p)
		return {INT_MAX, 0};
	
	auto r1 = get(idx*2, s, e, p, (p+q)/2);
	auto r2 = get(idx*2+1, s, e, (p+q)/2, q);
	return {min(r1.first, r2.first), max(r1.second, r2.second)};
}

int main()
{
	for (int i=1; i<TT; ++i)
		t[i].first = INT_MAX;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
	{
		int v;
		scanf("%d", &v);
		update(i, v);
	}

	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		auto res = get(1, a, b+1, 1, T+1);
		printf("%d %d\n", res.first, res.second);
	}

	return 0;
}