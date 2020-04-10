#include <cstdio>
#include <algorithm>
#include <queue>
#define N 200010

using namespace std;

int n;
pair<int,int> a[N];
priority_queue<int> pq;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d %d", &a[i].first, &a[i].second);

	sort(a, a+n);

	int cnt=0, res=0;
	for(int i=0; i<n; ++i)
	{
		while(!pq.empty() && -pq.top()<=a[i].first)
		{
			pq.pop();
			--cnt;
		}
		pq.push(-a[i].second);
		res = max(res, ++cnt);
	}

	printf("%d", res);
	return 0;
}
