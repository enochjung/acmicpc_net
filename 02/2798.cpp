#include <cstdio>
#define N 100

int n, m, a[N];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);

	int res = 0;
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			for (int k=j+1; k<n; ++k)
			{
				int sum = a[i]+a[j]+a[k];
				if (sum > res && sum <= m)
					res = sum;
			}

	printf("%d\n", res);
	return 0;
}