#include <stdio.h>
#define N 110

using namespace std;

int n, m, a[N][N];
bool set[N], origin[N];

int* get(int k)
{
    if(!set[k])
    {
        bool change = false;
        
        for(int i=0; i<n; i++)
            if(a[k][i] > 0) {
                int* res = get(i);
                
                if(!origin[i]) {
                    for(int j=0; j<n; j++)
                        if(*(res+j) > 0)
                            a[k][j] += (*(res+j))*a[k][i];
                    a[k][i] = 0;
                }
                
                change = true;
            }
        
        if(!change)
            origin[k] = true;
        set[k] = true;
    }
    
    return a[k];
}

int main()
{
    scanf("%d %d", &n, &m);
    
    while(m--) {
        int x, y, k;
        cin >> x >> y >> k;
        x--, y--;
        a[x][y] = k;
    }
    
    int* res = get(n-1);
    for(int i=0; i<n; i++)
        if(*(res+i) > 0)
            printf("%d %d", i+1, *(res+i));
}
