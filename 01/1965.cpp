#include <stdio.h>
#include <algorithm>

using namespace std;

int n, d[1010], len;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int v;
		scanf("%d", &v);

		int idx = (lower_bound(d, d+len, v)-d);
		d[idx] = v;
		if(len == idx) len++;
	}
	printf("%d", len);

	return 0;
}
