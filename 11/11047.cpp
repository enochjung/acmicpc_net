#include <cstdio>

int n, k, a[10];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int res = 0;
	for(int i=n-1; i>=0; --i)
	{
		res += k/a[i];
		k %= a[i];
	}

	printf("%d", res);
	return 0;
}
