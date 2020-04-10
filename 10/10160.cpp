#include <cstdio>
#define R 1000000009

int n, k;
long long d[7] = {1};

int main()
{
    scanf("%d %d", &n, &k);
    
    for(int i=1; i<=n; i++)
		d[i%7] = (d[(i+6)%7]*k-d[(i+2)%7]*2+d[i%7]) % R;
    
    printf("%lld", (d[n%7]+R)%R);
    return 0;
}
