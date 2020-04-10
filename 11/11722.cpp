#include <stdio.h>
#include <algorithm>

using namespace std;

int n, d[1010], len;

int main()
{
	scanf("%d", &n);

	while(n--)
	{
		int v;
		scanf("%d", &v);

		int idx = (int)(lower_bound(d, d+len, 1000-v)-d);
		d[idx] = 1000-v;
		if(idx == len) len++;
	}

	printf("%d", len);
	return 0;
}
