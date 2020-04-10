#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

int t, n, k, w;
int d[1010], a[1010];
vector<int> v[1010];

int max(int a, int b) {return a>b?a:b;}

int f(int p)
{
    if(a[p] == -1) {
        int res = 0;
        for(int i=0; i<v[p].size(); i++)
            res = max(res, f(v[p][i]));
        a[p] = res+d[p];
    }
    return a[p];
}

int main()
{
    for(scanf("%d",&t); t--;)
    {
        memset(a, -1, sizeof(a));
        for(int i=0; i<n; i++)
            v[i].clear();
        
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++)
            scanf("%d", d+i);
        for(int i=0; i<k; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            v[y-1].push_back(x-1);
        }
        scanf("%d", &w);
        
        printf("%d\n", f(w-1));
    }
}
