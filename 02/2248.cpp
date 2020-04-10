#include <cstdio>

int n, l;
long long i;
int d[40][40];

int min(int x, int y)
{
    return x<y? x : y;
}

int main()
{
    scanf("%d %d %lld", &n, &l, &i);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
        {
            if(j == 0)
                d[i][j] = 1;
            else if(j == i)
                d[i][j] = 1<<i;
            else
                d[i][j] = d[i-1][j-1] + d[i-1][j];
        }
    
    for(int k=n-1; k>=0; k--)
    {
        if(d[k][min(k,l)] < i)
        {
            i -= d[k][min(k,l--)];
            printf("1");
        }
        else
            printf("0");
    }
    
    return 0;
}
