#include <cstdio>

int n;
bool a[510][510];

int main()
{
    scanf("%d", &n);
    
    int p = 1;
    printf("a1 ");
    
    int c = n/2;
    for(int k=n*(n-1)/2; k>0; k--)
    {
        int t;
        for(t=1; t<=n; t++)
            if(!a[p][t] && p!=t && (t!=1 || (c>1 || k==1)))
                break;
            
        a[p][t] = a[t][p] = true;
        p = t;
        printf("a%d ", p);
        if(p == 1)
            c--;
    }
    
    return 0;
}
