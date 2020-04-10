#include <cstdio>

int n;

bool f(int x)
{
	int cnt = 0;
	while(x)
	{
		if(x%10 == 6)
			++cnt;
		else
			cnt = 0;
		if(cnt == 3)
			return true;
		x /= 10;
	}
	return false;
}

int main()
{
	scanf("%d", &n);

	int cnt = 0;
	for(int i=666; i<2666800; ++i)
		if(f(i))
		{
			++cnt;
			if(cnt == n)
			{
				printf("%d", i);
				return 0;
			}
		}

	return 0;
}
