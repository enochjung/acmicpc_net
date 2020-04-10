#include <cstdio>
#define N 20

int n, a[N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);

		int p = 0;
		while(true)
		{
			if(a[p] == 0)
				--v;
			if(v < 0)
				break;
			++p;
		}
		a[p] = i+1;
	}

	for(int i=0; i<n; ++i)
		printf("%d ", a[i]);
	return 0;
}
