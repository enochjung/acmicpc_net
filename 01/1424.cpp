#include <cstdio>

int n, l, c;

int main()
{
	scanf("%d %d %d", &n, &l, &c);
	int m = (c+1)/(l+1);
	if(m%13 == 0)
		--m;
	int last = n%m;
	printf("%d", (n+m-1)/m + (((n+m-1)/m==1 && n%13==0) || (last==m-1 && last%13==0 && last>0)? 1 : 0));
	return 0;
}
