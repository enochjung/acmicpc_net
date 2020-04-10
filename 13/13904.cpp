#include <cstdio>
#include <algorithm>
#define N 1010
#define D 1010

using namespace std;

struct st
{
	int d, w;
	bool operator<(const st &hs) const
	{
		return w>hs.w;
	}
};

int n;
st a[N];
bool v[D];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d %d", &a[i].d, &a[i].w);

	sort(a, a+n);

	int res = 0;
	for(int i=0; i<n; ++i)
	{
		int j = a[i].d;
		for(; v[j] && j>0; --j);
		if(j > 0)
		{
			res += a[i].w;
			v[j] = true;
		}
	}
	printf("%d", res);
	return 0;
}
