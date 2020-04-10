#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int d[1010], len;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int v;
		scanf("%d", &v);
		
		int idx = (int)(lower_bound(d, d+len, v) - d);
		if(idx == len) len++;
		d[idx] = v;
	}
	printf("%d", len);
}
