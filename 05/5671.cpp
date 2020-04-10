#include <cstdio>

int n, m;

bool f(int x)
{
	bool v[10] = {};

	while(x)
	{
		if(v[x%10])
			return false;
		v[x%10] = true;
		x /= 10;
	}
	return true;
}

int main()
{
	while(scanf("%d %d", &n, &m) == 2)
	{
		int res = 0;
		while(n <= m)
			if(f(n++))
				++res;
		printf("%d\n", res);
	}
	
	return 0;
}
