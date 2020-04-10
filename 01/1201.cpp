#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, k;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	if(k>n-m+1 || k<(n+m-1)/m)
	{
		printf("-1");
		return 0;
	}

	while(k)
	{
		int num = min(m, n-k+1);
		for(int i=n-num+1; i<=n; ++i)
			printf("%d ", i);
		n -= num;
		--k;
	}

    return 0;
}
