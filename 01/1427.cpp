#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int n, a[10];

int main()
{
	scanf("%d", &n);

	int l;
	for(l=0; n; l++)
	{
		a[l] = n%10;
		n /= 10;
	}

	sort(a, a+l, greater<int>());

	for(int i=0; i<l; i++)
		printf("%d", a[i]);
	return 0;
}
