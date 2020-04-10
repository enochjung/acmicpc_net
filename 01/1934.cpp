#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int t, a, b;

int gcd(int x, int y) {
    if(x%y == 0)
        return y;
    return gcd(y, x%y);
}

int main()
{
    for(scanf("%d",&t); t--;) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a*b/gcd(MAX(a,b),MIN(a,b)));
    }
}
