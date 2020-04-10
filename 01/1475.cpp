#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[10];

int main()
{
	scanf("%d", &n);

	do
	{
		a[n%10]++;
		n /= 10;
	}while(n);

	a[6] += a[9];
	a[6] = (a[6]+1)/2;

	int res = 0;
	for(int i=0; i<9; i++)
		res = max(res, a[i]);
	printf("%d\n", res);
	return 0;
}
