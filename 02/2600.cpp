#include <stdio.h>
#include <string.h>

int n[3], k[2];
int d[510][510];

bool f(int a, int b)
{
    if(a<0 || b<0) return true;
    if(d[a][b] == -1) {
        bool x = 1;
        for(int i=0; i<3; i++)
            x &= f(a-n[i],b)&f(a,b-n[i]);
        d[a][b] = !x;
    }
    return d[a][b];
}

int main()
{
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    
    scanf("%d %d %d", n+0, n+1, n+2);
    for(int t=0; t<5; t++) {
        scanf("%d %d", k+0, k+1);
        printf("%c\n", f(k[0],k[1])?'A':'B');
    }
}
