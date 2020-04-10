#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
pair<int,int> a[300010];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(x <= y)
			n--, i--;
		else
			a[i].first=m-x, a[i].second=m-y;
	}
	
	sort(a, a+n);

	long long res = 0;
	int r = -1;
	for(int i=0; i<n; i++)
	{
		if(r < a[i].first)
		{
			r = a[i].second;
			res += r-a[i].first;
		}
		else if(r < a[i].second)
		{
			res += a[i].second-r;
			r = a[i].second;
		}
	}

	printf("%lld\n", m+res*2);
	return 0;
}
