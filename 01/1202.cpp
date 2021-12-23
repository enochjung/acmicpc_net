#include <cstdio>
#include <algorithm>
#include <queue>
#define N 300000

using namespace std;

int n, k;
pair<int,int> a[N];
int b[N];
priority_queue<int> pq;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; ++i)
		scanf("%d %d", &a[i].first, &a[i].second);
	for (int j=0; j<k; ++j)
		scanf("%d", b+j);

	sort(a, a+n);
	sort(b, b+k);

	long long res = 0;
	for (int i=0,j=0; j<k; ++j)
	{
		while (i<n && a[i].first<=b[j])
		{
			pq.push(a[i].second);
			++i;
		}

		if (!pq.empty())
		{
			res += pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", res);
	return 0;
}