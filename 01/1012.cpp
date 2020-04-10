#include <stdio.h>
#include <string.h>

int t, m, n, k, cnt;
bool a[60][60];
int px[]={-1,0,1,0}, py[]={0,-1,0,1};

void change(int x, int y)
{
    a[x][y] = 0;
    for(int i=0; i<4; i++)
        if(0<=x+px[i] && x+px[i]<m && 0<=y+py[i] && y+py[i]<n
           && a[x+px[i]][y+py[i]])
            change(x+px[i], y+py[i]);
}

int main()
{
    for(scanf("%d",&t); t--;)
    {
        scanf("%d %d %d", &m, &n, &k);
        for(int i=0; i<k; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            a[x][y] = 1;
        }
        
        cnt = 0;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(a[i][j]) {
                    change(i, j);
                    cnt++;
                }
        
        printf("%d\n", cnt);
        
        memset(a, sizeof(a), 0);
    }
}
