#include <cstdio>
#include <algorithm>
#include <vector>
#define N 2010
#define M 10010

using namespace std;

struct st
{
	int a, b, c;
	bool operator<(const st &hs) const
	{
		return b!=hs.b? b<hs.b : a>hs.a;
	}
};

int n, c, m, d[N];
st q[M];

int main()
{
	scanf("%d %d %d", &n, &c, &m);
	for(int i=0; i<m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		q[i] = {a, b, c};
	}

	sort(q, q+m);

	int res = 0;
	for(int i=0; i<m; ++i)
	{
		int p = q[i].c;
		for(int j=q[i].a; j<q[i].b; ++j)
			p = min(p, c-d[j]);
		for(int j=q[i].a; j<q[i].b; ++j)
			d[j] += p;
		res += p;
	}
	printf("%d", res);
	return 0;
}
