#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int n, m, a[100010], b[100010];
int plugA, plugB;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	for(int j=0; j<m; j++)
		scanf("%d", b+j);

	sort(a, a+n, greater<int>());
	sort(b, b+m, greater<int>());

	plugA = 1;
	plugB = 0;

	for(int i=0,j=0; i<n && j<m; i++)
	{
		plugA--;
		plugB += a[i];
		while(plugB && j<m)
		{
			plugB--;
			plugA += b[j];
			j++;
		}
	}

	printf("%d\n", plugA);
	return 0;
}
