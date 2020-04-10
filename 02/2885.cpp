#include <cstdio>

int k, b, r;

int main()
{
	scanf("%d", &k);
	for(b=1; b<k; b<<=1);
	for(int t=b; t>(k&-k); t>>=1,r++);
	printf("%d %d\n", b, r);
	return 0;
}
