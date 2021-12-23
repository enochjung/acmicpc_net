#include <cstdio>
#include <algorithm>
#include <stack>
#define N 100000

using namespace std;

struct graham
{
	long long x, y;
	long long p, q;
	bool operator<(const graham &hs) const
	{
		if (q*hs.p != p*hs.q)
			return q*hs.p < p*hs.q;
		return y!=hs.y? y<hs.y : x<hs.x;
	}
};

int n;
graham p[N];
stack<int> s;

long long ccw(graham &a, graham &b, graham &c)
{
	return a.x*b.y+b.x*c.y+c.x*a.y - (a.y*b.x+b.y*c.x+c.y*a.x);
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		p[i] = {x, y, 0, 0};
	}

	sort(p, p+n);
	for (int i=1; i<n; ++i)
	{
		p[i].p = p[i].x-p[0].x;
		p[i].q = p[i].y-p[0].y;
	}
	sort(p+1, p+n);

	s.push(0);
	s.push(1);
	for (int i=2; i<n; ++i)
	{
		while (s.size() >= 2)
		{
			int b = s.top();
			s.pop();
			int a = s.top();

			if (ccw(p[a], p[b], p[i]) > 0)
			{
				s.push(b);
				break;
			}
		}
		s.push(i);
	}

	printf("%d\n", (int)s.size());
	return 0;
}