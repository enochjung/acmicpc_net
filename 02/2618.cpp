#include <stdio.h>
#include <stdlib.h>
#define W 1010

int n, w, x[W], y[W], d[W][W];
bool p[W][W];

int dis(int i,int j){return j==w+2?0:abs(x[i]-x[j])+abs(y[i]-y[j]);}

int f(int i, int t)
{
    if(t==w+2) return 0;
    
    if(!d[i][t])
    {
        int a = f(i,t+1)+dis(t,t+1);
        int b = f(t,t+1)+dis(i,t+1);
        
        d[i][t] = a<b?a:b;
        p[i][t] = a<b;
    }
    
    return d[i][t];
}

int main()
{
    scanf("%d %d", &n, &w);
    for(int i=2; i<w+2; i++)
        scanf("%d %d", x+i, y+i);
    
    x[0]=y[0]=1;
    x[1]=y[1]=n;
    
    printf("%d\n", f(0,1));
    for(int i=0,j=1,c=0; j<=w; j++) {
        if(p[i][j]) printf("%d\n",2-c);
        else        printf("%d\n",c+1), i=j, c=1-c;
    }
}
