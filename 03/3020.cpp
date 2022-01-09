#include <cstdio>
#include <algorithm>
#define N 100010

using namespace std;

int n, h, a[N], b[N];

int main()
{
	scanf("%d %d", &n, &h);
	n /= 2;
	for(int i=0; i<n; ++i)
		scanf("%d %d", a+i, b+i);

	sort(a, a+n);
	sort(b, b+n);

	int val=n*2, cnt=0;
	for(int i=0; i<h; ++i)
	{
		int hit = n*2-((lower_bound(a,a+n,i+1)-a)+(lower_bound(b,b+n,h-i)-b));
		if(val > hit)
		{
			val = hit;
			cnt = 1;
		}
		else if(val == hit)
			++cnt;
	}

	printf("%d %d", val, cnt);
	return 0;
}