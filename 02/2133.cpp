#include <stdio.h>

int n, d[40]={1,0,3}, s;

int main()
{
    scanf("%d", &n);
    
    for (int i=4; i<=n; i+=2) {
        s += 2*d[i-4];
        d[i] = 3*d[i-2]+s;
    }
    
    printf("%d", d[n]);

	return 0;
}
