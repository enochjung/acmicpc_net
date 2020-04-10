#include <cstdio>

int n, a[1000010];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int res = 0;
	for(int i=0; i<n; ++i)
		if(a[i])
		{
			++res;
			a[i+1] = 1-a[i+1];
			a[i+2] = 1-a[i+2];
		}

	printf("%d", res);
	return 0;
}
