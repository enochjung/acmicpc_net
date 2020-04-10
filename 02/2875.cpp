#include <cstdio>
#include <algorithm>

using namespace std;

int m, n, k;

int main()
{
	scanf("%d %d %d", &m, &n, &k);

	while(k--)
	{
		if(m > n*2)
			m--;
		else
			n--;
	}

	printf("%d\n", min(m/2, n));
	return 0;
}
