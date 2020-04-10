#include <cstdio>
#include <algorithm>
#define N 1010

using namespace std;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);
	a[n] = 1999999999;

	int sum = 1;
	for(int i=0; i<=n; ++i)
	{
		if(a[i] <= sum)
			sum += a[i];
		else
		{
			printf("%d", sum);
			break;
		}
	}

	return 0;
}
