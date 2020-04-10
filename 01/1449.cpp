#include <cstdio>
#include <algorithm>
#define N 1010

using namespace std;

int n, l, a[N];

int main()
{
	scanf("%d %d", &n, &l);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	int res=0, last=0;
	for(int i=0; i<n; ++i)
		if(last <= a[i])
		{
			++res;
			last = a[i]+l;
		}
	printf("%d", res);
	return 0;
}
