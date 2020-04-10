#include <cstdio>

int e, s, m;

int main()
{
	scanf("%d %d %d", &e, &s, &m);
	--e, --s, --m;

	int res = 1;
	while(e || s || m)
	{
		e = (e+14)%15;
		s = (s+27)%28;
		m = (m+18)%19;
		++res;
	}

	printf("%d", res);
	return 0;
}
