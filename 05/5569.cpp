#include <cstdio>
#define R 100000

int w, h, d[110][110][4];

int main()
{
    scanf("%d %d", &w, &h);
    
    d[0][1][1] = 1;
    d[1][0][3] = 1;
    
    for(int i=1; i<=w; i++)
        for(int j=1; j<=h; j++)
        {
            d[i][j][0] = (d[i-1][j][0]+d[i-1][j][1])%R;
            d[i][j][1] = d[i][j-1][2];
            d[i][j][2] = (d[i][j-1][2]+d[i][j-1][3])%R;
            d[i][j][3] = d[i-1][j][0];
        }
    
    printf("%d\n", (d[w][h][0]+d[w][h][2])%R);
    return 0;
}
