#include <cstdio>

int t, x, n, y;
long long f[90] = {0, 1};

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    while(a % b)
    {
        long long tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

int main()
{
    for(int i=2; i<=80; i++)
        f[i] = f[i-1]+f[i-2];
    
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d %d %d %*d", &x, &n, &y);
        printf("Case %d: %lld\n", i, gcd(f[n+1]*x+y, f[n]*x));
    }
    return 0;
}
