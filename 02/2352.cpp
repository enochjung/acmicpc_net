#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[40010];
int d[40010], len;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);

	for(int i=0; i<n; i++)
	{
		int idx = (int)(lower_bound(d,d+len,a[i]) - d);
		d[idx] = a[i];
		if(idx == len)
			len++;
	}

	printf("%d\n", len);
	return 0;
}
