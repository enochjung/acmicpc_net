#include <cstdio>

int n, a[10];

void add(int p, int q, int v)
{
	for (int i=p; i<=q; ++i)
		a[i] += v;
}

int main()
{
	scanf("%d", &n);

	for (int i=1; i<=n; i*=10)
	{
		int ii = i*10;

		if (n >= ii)
		{
			add(1, 9, i);
			add(0, 9, (n/ii-1)*i);
			add(0, n%ii/i-1, i);
		}
		else
			add(1, n/i-1, i);
		add(n%ii/i, n%ii/i, n%i+1);
	}

	for (int i=0; i<10; ++i)
		printf("%d ", a[i]);
	return 0;
}