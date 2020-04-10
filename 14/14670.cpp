#include <cstdio>
#include <cstring>

int n, r, p[110];

int main()
{
	memset(p, -1, sizeof(p));

	scanf("%d", &n);
	while(n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		p[a] = b;
	}

	scanf("%d", &r);
	while(r--)
	{
		int l, s, w[110];
		bool die = false;
		scanf("%d", &l);
		for(int i=0; i<l; ++i)
		{
			scanf("%d", &s);
			if(p[s] == -1)
				die = true;
			w[i] = p[s];
		}
		if(die)
			printf("YOU DIED");
		else
			for(int i=0; i<l; ++i)
				printf("%d ", w[i]);
		printf("\n");
	}
}
