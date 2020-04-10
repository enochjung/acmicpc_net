#include <cstdio>
#include <algorithm>

using namespace std;

int n, t[20], p[20];
int d[30];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", t+i, p+i);

	for(int i=0; i<n; i++)
	{
		d[i+t[i]] = max(d[i+t[i]], d[i]+p[i]);
		d[i+1] = max(d[i+1], d[i]);
	}

	printf("%d\n", d[n]);
	return 0;
}
