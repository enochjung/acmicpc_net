#include <stdio.h>

int n, d[1010][3];

int min(int a,int b){return a<b?a:b;}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=0; j<3; j++)
            scanf("%d", &d[i][j]);
    
    for(int i=1; i<=n; i++) {
        d[i][0] += min(d[i-1][1], d[i-1][2]);
        d[i][1] += min(d[i-1][0], d[i-1][2]);
        d[i][2] += min(d[i-1][0], d[i-1][1]);
    }
    
    printf("%d", min(d[n][0], min(d[n][1], d[n][2])));
}
