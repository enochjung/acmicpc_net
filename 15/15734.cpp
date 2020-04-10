#include <cstdio>

int l, r, a;

int main()
{
	scanf("%d %d %d", &l, &r, &a);

	if(l > r)
		l ^= r ^= l ^= r;

	printf("%d", l+a<r? (l+a)*2 : (l+r+a)/2*2);
	return 0;
}
