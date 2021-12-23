#include <cstdio>
#define ZERO 4000000
#define M (ZERO*2+1)

int n, s;
long long d[M];

int main()
{
	scanf("%d %d", &n, &s);
	while (n--)
	{
		int val;
		scanf("%d", &val);
		if (val > 0)
			for (int i=M-1; i>=val; --i)
				d[i] += d[i-val];
		else
			for (int i=0; i<M+val; ++i)
				d[i] += d[i-val];
		++d[val+ZERO];
	}

	printf("%lld\n", d[s+ZERO]);
	return 0;
}