#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
pair<int,int> a[1000010];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);

	sort(a, a+n);

	int res = 0;
	int r = -1111111111;
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

	printf("%d\n", res);
	return 0;
}
