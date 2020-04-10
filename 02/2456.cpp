#include <cstdio>
#include <algorithm>

using namespace std;

int n;
struct st
{
	int i, s, a[4];
	bool operator<(const st &hs) const
	{
		return s!=hs.s? s>hs.s : a[3]!=hs.a[3]? a[3]>hs.a[3] : a[2]>hs.a[2];
	}
} p[3];

int main()
{
	scanf("%d", &n);
	for(int j=0; j<3; ++j)
		p[j].i = j+1;
	for(int i=0; i<n; ++i)
		for(int j=0; j<3; ++j)
		{
			int v;
			scanf("%d", &v);
			p[j].s += v;
			++p[j].a[v];
		}

	sort(p, p+3);

	if(p[0].a[3]!=p[1].a[3] || p[0].a[2]!=p[0].a[2])
		printf("%d %d", p[0].i, p[0].s);
	else
		printf("%d %d", 0, p[0].s);

	return 0;
}
