#include <cstdio>
#include <algorithm>
#define N 2010

using namespace std;

int n, a[N];
int res;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);
	for(int d=0; d<n; ++d)
		for(int i=0; i<n; ++i)
			if(i != d)
			{
				int idx = (int)(lower_bound(a,a+n,a[d]-a[i]) - a);
				if(idx<n && a[idx]==a[d]-a[i] && idx!=i)
				{
					res++;
					break;
				}
			}

	printf("%d", res);
	return 0;
}
