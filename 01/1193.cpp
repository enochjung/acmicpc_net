#include <cstdio>

int x, n;

int main()
{
    scanf("%d", &x);
    
    for(n=1; n*(n+1)/2<x; n++);
    
	int a = n*(n+1)/2-x+1;
	int b = n+x-n*(n+1)/2;

    printf("%d/%d", n&1?a:b, n&1?b:a);
    return 0;
}
