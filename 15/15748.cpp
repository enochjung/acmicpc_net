#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct st
{
	int x, c;
	bool operator<(const st &hs) const
	{
		return c!=hs.c? c>hs.c : x>hs.x;
	}
	bool operator==(const st &hs) const
	{
		return c>=hs.c && x>=hs.x;
	}
};

int l, n, f, b;
vector<st> a;

int main()
{
	scanf("%d %d %d %d", &l, &n, &f, &b);
	for(int i=0; i<n; ++i)
	{
		int x, c;
		scanf("%d %d", &x, &c);
		a.push_back({x, c});
	}
	a.push_back({0, 9999999});

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	long long res = 0;
	for(int i=1; i<(int)a.size(); ++i)
	{
		long long time = 1LL*(a[i].x-a[i-1].x)*(f-b);
		res += time*a[i].c;
	}
	printf("%lld", res);
	return 0;
}
