#include <cstdio>

int n, q, e[100010];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n-1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		++e[a], ++e[b];
	}

	scanf("%d", &q);
	while(q--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%s\n", a==2 || e[b]>1? "yes" : "no");
	}
	return 0;
}
