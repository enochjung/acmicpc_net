#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[1010];
int b[1010], c[1010], d[1010], len;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	
	len = 0;
	for(int i=0; i<n; i++)
	{
		b[i] = (int)(lower_bound(d, d+len, a[i]) - d);
		d[b[i]] = a[i];
		if(len == b[i]) len++;
	}

	len = 0;
	for(int i=n-1; i>=0; i--)
	{
		c[i] = (int)(lower_bound(d, d+len, a[i]) - d);
		d[c[i]] = a[i];
		if(len == c[i]) len++;
	}

	int res = 0;
	for(int i=0; i<n; i++)
		if(res < b[i]+c[i]+1)
			res = b[i]+c[i]+1;

	printf("%d", res);
	return 0;
}
