#include <cstdio>
#include <algorithm>
#define N 300010

using namespace std;

struct st
{
	int h, c;
	bool operator<(const st &hs) const
	{
		return h!=hs.h? h<hs.h : c<hs.c;
	}
};

struct comparator
{
	bool operator()(const st &lhs, int rhs)
	{
		return lhs.h < rhs;
	}
	bool operator()(int lhs, const st &rhs)
	{
		return lhs < rhs.h;
	}
};

int n, s;
st a[N];
int d[N];

int main()
{
	scanf("%d %d", &n, &s);
	for(int i=0; i<n; ++i)
		scanf("%d %d", &a[i].h, &a[i].c);

	sort(a, a+n);

	for(int i=0; i<n; ++i)
		if(a[i].h >= s)
		{
			int idx = (int)(upper_bound(a, a+n, a[i].h-s, comparator()) - a) - 1;
			if(idx == -1)
				d[i] = max(a[i].c, i? d[i-1] : 0);
			else
				d[i] = max(a[i].c+d[idx], d[i-1]);
		}

	printf("%d", d[n-1]);
	return 0;
}
