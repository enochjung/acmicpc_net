#include <stdio.h>
#include <string.h>

int n, v, rx, ry;
int a[1010][1010];
const int mx[4]={0,1,0,-1}, my[4]={1,0,-1,0};

int main()
{
    memset(a, -1, sizeof(a));
    
    scanf("%d %d", &n, &v);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            a[i][j] = 0;
    
    int x=1, y=1, way=0;
    for(int d=n*n; d>0; d--)
    {
        a[x][y] = d;
        if(v == d)
            rx=x, ry=y;
        if(a[x+mx[way]][y+my[way]] != 0)
            way = (way+1)%4;
        x += mx[way];
        y += my[way];
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            printf("%d ", a[j][i]);
        printf("\n");
    }
    printf("%d %d", ry, rx);
}
