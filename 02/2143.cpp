#include <cstdio>
#include <algorithm>
#include <vector>
#define N 1000

using namespace std;

int t, n, m, a[N], b[N];
vector<int> va, vb;

int main()
{
	scanf("%d %d", &t, &n);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);
	scanf("%d", &m);
	for (int i=0; i<m; ++i)
		scanf("%d", b+i);

	for (int i=0; i<n; ++i)
	{
		int sum = 0;
		for (int j=i; j<n; ++j)
		{
			sum += a[j];
			va.push_back(sum);
		}
	}
	for (int i=0; i<m; ++i)
	{
		int sum = 0;
		for (int j=i; j<m; ++j)
		{
			sum += b[j];
			vb.push_back(sum);
		}
	}
	sort(vb.begin(), vb.end());

	long long res = 0;
	for (int av : va)
	{
		int si = (int)(lower_bound(vb.begin(), vb.end(), t-av) - vb.begin());
		int ei = (int)(upper_bound(vb.begin(), vb.end(), t-av) - vb.begin());
		res += ei-si;
	}

	printf("%lld\n", res);
	return 0;
}