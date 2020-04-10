#include <cstdio>
#define C 1010

int n, a, b, j, c;
double d[2][C];

int main()
{
    scanf("%d %d", &n, &a);
    b += a;
    for(int i=1; i<n; ++i)
    {
        int v;
        scanf("%d", &v);
        b += v;
    }
    scanf("%d %d", &j, &c);
    
    d[0][0] = 1;
    for(int t=0; t<c; ++t)
    {
        int tt = t&1;
        for(int i=0; i<=t+1; ++i)
            d[1-tt][i] = 0;
        for(int i=0; i<=t; ++i)
        {
            int ra = a+i*j;
            int rb = b+t*j;
            
            d[1-tt][i] += d[tt][i]*(rb-ra)/rb;
            d[1-tt][i+1] += d[tt][i]*ra/rb;
        }
    }
    
    double res = 0;
    for(int i=0; i<=c; ++i)
        res += d[c&1][i]*(a+i*j);
    printf("%.11lf", res);
    return 0;
}
