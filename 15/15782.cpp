#include <cstdio>
#include <vector>
#define N 100010
#define MAX 1<<18

using namespace std;

int n, m;
int v[MAX], l[MAX];
vector<int> edge[N];
int st[N], en[N];
bool visited[N];

class segment_tree
{
private:
    int start;
    
    void propagate(int idx, int width)
    {
        if(l[idx])
        {
            if(idx < start)
            {
                l[idx*2] ^= l[idx];
                l[idx*2+1] ^= l[idx];
            }
            else
                v[idx] ^= l[idx]*width;
            l[idx] = 0;
        }
    }
    
    void xor_(int idx, int s, int e, int a, int b, int val)
    {
        propagate(idx, e-s);
        
        if(b<=s || e<=a)
            return;
        
        if(a<=s && e<=b)
        {
            l[idx] ^= val;
            propagate(idx, e-s);
            return;
        }
        
        int mid = (s+e)/2;
        xor_(idx*2, s, mid, a, b, val);
        xor_(idx*2+1, mid, e, a, b, val);
        v[idx] = v[idx*2]^v[idx*2+1];
    }
    
    int get(int idx, int s, int e, int a, int b)
    {
        propagate(idx, e-s);
        
        if(b<=s || e<=a)
            return 0;
        
        if(a<=s && e<=b)
            return v[idx];
        
        int mid = (s+e)/2;
        return get(idx*2, s, mid, a, b) ^ get(idx*2+1, mid, e, a, b);
    }
    
public:
    segment_tree(int start)
    {
        this->start = start;
        for(int i=start-1; i>=1; --i)
            v[i] = v[i*2]^v[i*2+1];
    }
    
    void xor_(int a, int b, int val)
    {
        xor_(1, 0, start, a, b, val);
    }
    
    int get(int a, int b)
    {
        return get(1, 0, start, a, b);
    }
};

void f(int x)
{
    static int cnt = 0;
    
    visited[x] = true;
    st[x] = cnt++;
    for(int to : edge[x])
        if(!visited[to])
            f(to);
    en[x] = cnt;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n-1; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    f(1);
    int start;
    for(start=1; start<n; start<<=1);
    for(int i=1; i<=n; ++i)
    {
        int a;
        scanf("%d", &a);
        v[st[i]+start] = a;
    }
    segment_tree s(start);
    
    while(m--)
    {
        int t, x, y;
        scanf("%d", &t);
        if(t == 1)
        {
            scanf("%d", &x);
            printf("%d\n", s.get(st[x], en[x]));
        }
        else
        {
            scanf("%d %d", &x, &y);
            s.xor_(st[x], en[x], y);
        }
    }
    
    return 0;
}
