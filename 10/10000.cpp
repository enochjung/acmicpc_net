#include <stdio.h>
#include <algorithm>

using namespace std;

struct st
{
	int s, e;
	bool operator<(const st &i) const
	{
		return e!=i.e? e<i.e : s>i.s;
	}
} a[300010];

int n;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int x, r;
		scanf("%d %d", &x, &r);
		a[i].s = x-r;
		a[i].e = x+r;
	}
	
	sort(a, a+n);

	int res = 1;
	int left=0, right=-2111111111;
	for(int i=0; i<n; i++)
	{
		if(a[i].s<=left && a[i].e==right)
			res++;
		else if(right < a[i].s)
		{
			left = a[i].s;
			right = a[i].e;
		}
		else
		{
			left = min(left, a[i].s);
			right = max(right, a[i].e);
		}
		res++;
	}

	printf("%d\n", res);
	return 0;
}
