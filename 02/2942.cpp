#include <cstdio>

int r, g;

int gcd(int x, int y)
{
	while(x%y)
	{
		int t = x%y;
		x = y;
		y = t;
	}
	return y;
}

int main()
{
	scanf("%d %d", &r, &g);

	int v = gcd(r, g);
	for(int i=1; i*i<=v; i++)
		if(v%i == 0)
		{
			printf("%d %d %d\n", i, r/i, g/i);
			if(i*i != v)
				printf("%d %d %d\n", v/i, r/v*i, g/v*i);
		}
	return 0;
}
