#include <cstdio>
#include <algorithm>
#define N 5000
#define W 800000

int w, n, a[N];
int b[W];

int main()
{
	scanf("%d %d", &w, &n);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);

	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
		{
			int s = a[i]+a[j];
			if (s < w)
			{
				if (0<b[w-s] && b[w-s]<i)
				{
					printf("YES\n");
					return 0;
				}
				b[s] = b[s]==0? j : std::min(b[s],j);
			}
		}
	printf("NO\n");
	return 0;
}