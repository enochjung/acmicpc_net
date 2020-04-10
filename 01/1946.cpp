#include <cstdio>
#include <algorithm>

using namespace std;

int t, n;
pair<int,int> a[100010];

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			scanf("%d %d", &a[i].first, &a[i].second);

		sort(a, a+n);

		int res = 0;
		int rank = n+1;
		for(int i=0; i<n; ++i)
			if(a[i].second < rank)
			{
				++res;
				rank = a[i].second;
			}
		printf("%d\n", res);
	}
	
	return 0;
}
