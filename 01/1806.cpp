#include <cstdio>
#include <algorithm>
#define N 100000

using namespace std;

int n, s, a[N];

int main()
{
	scanf("%d %d", &n, &s);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);
	
	int i=0, j=0, sum=0;
	int res = n+1;
	while (true)
	{
		if (sum < s)
		{
			if (j == n)
				break;
			sum += a[j++];
		}
		else
		{
			res = min(res, j-i);
			sum -= a[i++];
		}
	}

	printf("%d\n", res<n+1? res : 0);
	return 0;
}