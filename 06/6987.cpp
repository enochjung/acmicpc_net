#include <stdio.h>

int a[6][3], sum;

bool dfs(int i, int j)
{
    if(i==5) return true;
    if(j==6) return dfs(i+1,i+2);
    
    for(int k=0; k<3; k++)
        if(a[i][k] && a[j][2-k]) {
            a[i][k]--, a[j][2-k]--;
            if(dfs(i,j+1)) return true;
            a[i][k]++, a[j][2-k]++;
        }
    
    return false;
}

int main()
{
    for(int t=0; t<4; t++)
    {
        sum = 0;
        for(int i=0; i<6; i++)
            for(int j=0; j<3; j++) {
                scanf("%d", &a[i][j]);
                sum += a[i][j];
            }
        printf("%d ", sum!=30? 0 : dfs(0,1));
    }
}
