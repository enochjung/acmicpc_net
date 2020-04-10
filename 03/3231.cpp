#include <cstdio>

int n, a[100010];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		a[v-1] = i;
	}

	int res = 0;
	for(int i=0; i<n-1; ++i)
		if(a[i+1] < a[i])
			++res;

	printf("%d", res);
	return 0;
}
