#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#define N 100000
#define V 10000

using namespace std;

struct point
{
	int x, y;
	bool operator<(const point &hs) const
	{
		return y!=hs.y? y<hs.y : x<hs.x;
	}
};

int n;
point a[N];
set<point> s;

int dist(point a, point b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d %d", &a[i].x, &a[i].y);

	sort(a, a+n, [](point &a, point &b) { return a.x<b.x; });

	int res = dist(a[0], a[1]);
	s.insert(a[0]);
	s.insert(a[1]);
	for (int i=2,j=0; i<n; ++i)
	{
		int d = (int)sqrt(res);

		while (j<i && a[j].x+d<a[i].x)
			s.erase(a[j++]);

		auto lower = s.lower_bound({-V, a[i].y-d});
		auto upper = s.upper_bound({V, a[i].y+d});
		for (auto it=lower; it!=upper; ++it)
			res = min(res, dist(a[i], *it));
		
		s.insert(a[i]);
	}

	printf("%d\n", res);
	return 0;
}