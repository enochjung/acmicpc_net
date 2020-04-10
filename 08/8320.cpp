#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);

	int res = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j*j<=i; ++j)
			if(i%j == 0)
				++res;

	printf("%d", res);
	return 0;
}
