#include <cstdio>
#define R ((int)1e9)

int n, d[3][200];

void f(int x, int y, int z)
{
    for(int i=0,r=0;; i++)
    {
        d[z][i] = (d[x][i]+d[y][i]+r) % R;
        r = (d[x][i]+d[y][i]+r) / R;
        
        if(d[x][i]==0 && d[y][i]==0 && r==0)
            break;
    }
}

void print(int x)
{
    int i;
    for(i=0; d[x][i+1]; i++);
    
    printf("%d", d[x][i]);
    while(i > 0)
        printf("%09d", d[x][--i]);
    printf("\n");
}

int main()
{
    scanf("%d", &n);
    
    d[0][0] = 0;
    d[1][0] = 1;
    
    for(int i=2; i<=n; i++)
        f((i-2)%3, (i-1)%3, i%3);
    print(n%3);
    return 0;
}
