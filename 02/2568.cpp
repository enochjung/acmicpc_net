#include <cstdio>
#include <algorithm>
#define N 100000

using std::sort;
using std::lower_bound;

struct pair
{
	int a, b;
	bool operator<(const pair &hs) const
	{
		return a < hs.a;
	}
	bool operator<(int i) const
	{
		return b < i;
	}
};

int n;
pair l[N], d[N];
int p[N];
bool c[N];

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d %d", &l[i].a, &l[i].b);
	
	sort(l, l+n);

	int len = 0;
	for (int i=0; i<n; ++i)
	{
		int idx = (int)(lower_bound(d, d+len, l[i].b) - d);
		p[i] = idx>0? d[idx-1].a : -1;
		d[idx] = {i, l[i].b};
		if (idx == len)
			++len;
	}

	for (int i=d[len-1].a; i>=0; i=p[i])
		c[i] = true;

	printf("%d\n", n-len);
	for (int i=0; i<n; ++i)
		if (!c[i])
			printf("%d\n", l[i].a);
	return 0;
}