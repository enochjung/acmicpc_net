#include <cstdio>
#include <algorithm>
#define N 300010

using namespace std;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);

	int res=0, mv=0;
	for(int i=n-1; i>=0; --i)
	{
		if(a[i]+n >= mv)
			++res;
		mv = max(mv, a[i]+(n-i));
	}
	printf("%d", res);
	return 0;
}
