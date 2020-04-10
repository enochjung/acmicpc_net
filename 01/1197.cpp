#include <cstdio>
#include <algorithm>

using namespace std;

struct edge
{
    int s, e, c;
    bool operator<(const edge &i) const
    {
        return c < i.c;
    }
};

int v, e;
edge p[100010];
int g[10010];
long long res;

int find(int x)
{
    return x==g[x]? x : g[x]=find(g[x]);
}

int main()
{
    scanf("%d %d", &v, &e);
    for(int i=0; i<e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        p[i] = {a, b, c};
    }
    for(int i=1; i<=v; i++)
        g[i] = i;
    
    sort(p, p+e);
    
    for(int i=0; i<e; i++)
    {
        int a = find(p[i].s);
        int b = find(p[i].e);
        
        if(a != b)
        {
            g[a] = b;
            res += p[i].c;
        }
    }
    
    printf("%lld\n", res);
    return 0;
}
