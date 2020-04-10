#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int b[3], a[3][1010];
int m;

int main()
{
	for(int i=0; i<3; ++i)
		scanf("%d", b+i);
	for(int i=0; i<3; ++i)
		for(int j=0; j<b[i]; ++j)
			scanf("%d", &a[i][j]);

	m = min({b[0], b[1], b[2]});

	for(int i=0; i<3; ++i)
		sort(a[i], a[i]+b[i], greater<int>());

	int res1 = 0;
	int res2 = 0;
	for(int i=0; i<3; ++i)
		for(int j=0; j<b[i]; ++j)
		{
			res1 += a[i][j];
			res2 += j<m? a[i][j]*9/10 : a[i][j];
		}

	printf("%d\n%d", res1, res2);
	return 0;
}
