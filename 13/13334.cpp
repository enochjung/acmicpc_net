#include <cstdio>
#include <algorithm>
#define N 100000

using namespace std;

int n, m, d;
pair<int,int> a[N];
int s[N], e[N];

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		scanf("%d %d", &a[i].first, &a[i].second);
		if (a[i].first > a[i].second)
			swap(a[i].first, a[i].second);
	}
	scanf("%d", &d);

	for (int i=0; i<n; ++i)
		if (a[i].second-a[i].first <= d)
		{
			s[m] = a[i].first;
			e[m] = a[i].second;
			++m;
		}

	sort(s, s+m);
	sort(e, e+m);

	int res = 0;
	for (int i=0,j=0; i<m; ++i)
	{
		for (; j<m && s[j]<e[i]-d; ++j);
		res = max(res, i+1-j);
	}

	printf("%d\n", res);
	return 0;
}