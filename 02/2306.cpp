#include <stdio.h>
#include <string.h>

char s[510];
int d[510][510];

int max(int a,int b){return a>b?a:b;}

int f(int a, int b)
{
    if(d[a][b] == -1)
    {
        d[a][b] = 0;
        if((s[a]=='a' && s[b-1]=='t') || (s[a]=='g' && s[b-1]=='c'))
            d[a][b] = f(a+1,b-1)+2;
        for(int i=a+1; i<=b-1; i++)
            d[a][b] = max(d[a][b],f(a,i)+f(i,b));
    }
    
    return d[a][b];
}

int main()
{
    scanf("%s", s);
    memset(d, -1, sizeof(d));
    printf("%d", f(0,(int)strlen(s)));
}
