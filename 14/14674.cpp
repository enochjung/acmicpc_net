#include <cstdio>
#include <algorithm>

using namespace std;

struct game
{
	int i;
	long long c, h;
	bool operator<(const game &g) const
	{
		return h*g.c!=g.h*c? h*g.c>g.h*c : c!=g.c? c<g.c : i<g.i;
	}
};

int n, k;
game g[1010];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
		scanf("%d %lld %lld", &g[i].i, &g[i].c, &g[i].h);

	sort(g, g+n);

	for(int i=0; i<k; ++i)
		printf("%d\n", g[i].i);
	return 0;
}
