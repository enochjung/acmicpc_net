#include <stdio.h>
#define MAX 99999999
#define COUPON 25
#define min(a,b) ((a)<(b)?(a):(b))

int n, m;
int d[110][30], res;
bool c[110];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0, v; i<m; i++) {
        scanf("%d", &v);
        c[v] = true;
    }
    
    for(int i=0; i<=n; i++)
        for(int j=0; j<=COUPON; j++)
            d[i][j] = MAX;
    d[0][0] = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=COUPON; j++)
            d[i][j] = min(d[i][j], d[i-1][j]+(c[i]?0:10000));
    
        if(i >= 3)
            for(int j=1; j<=COUPON; j++)
                d[i][j] = min(d[i][j], d[i-3][j-1]+25000);
    
        if(i >= 5)
            for(int j=2; j<=COUPON; j++)
                d[i][j] = min(d[i][j], d[i-5][j-2]+37000);
    
        for(int j=0; j<=COUPON-3; j++)
            d[i][j] = min(d[i][j], d[i-1][j+3]);
    }
    
    res = MAX;
    for(int j=0; j<=COUPON; j++)
        res = min(res, d[n][j]);
    printf("%d", res);
}
