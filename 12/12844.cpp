#include <cstdio>
#include <algorithm>
#define N 1<<20

using namespace std;

int n, m;
int start = N>>1;
int v[N], l[N];

void propagate(int idx)
{
    if(l[idx])
    {
        if(idx < start)
        {
            l[idx*2] ^= l[idx];
            l[idx*2+1] ^= l[idx];
        }
        else
            v[idx] ^= l[idx];
        l[idx] = 0;
    }
}

void update(int idx, int s, int e, int a, int b, int val)
{
    propagate(idx);
    
    if(b<=s || e<=a)
        return;
    
    if(a<=s && e<=b)
    {
        l[idx] ^= val;
        propagate(idx);
        return;
    }
    
    int mid = (s+e)/2;
    update(idx*2, s, mid, a, b, val);
    update(idx*2+1, mid, e, a, b, val);
    v[idx] = v[idx*2]^v[idx*2+1];
}

int get(int idx, int s, int e, int a, int b)
{
    propagate(idx);
    
    if(b<=s || e<=a)
        return 0;
    
    if(a<=s && e<=b)
        return v[idx];
    
    int mid = (s+e)/2;
    return get(idx*2, s, mid, a, b) ^ get(idx*2+1, mid, e, a, b);
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        int v;
        scanf("%d", &v);
        update(1, 0, start, i, i+1, v);
    }
    
    scanf("%d", &m);
    while(m--)
    {
        int t, a, b, c;
        scanf("%d", &t);
        
        if(t == 1)
        {
            scanf("%d %d %d", &a, &b, &c);
            update(1, 0, start, min(a,b), max(a,b)+1, c);
        }
        else
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", get(1, 0, start, min(a,b), max(a,b)+1));
        }
    }
    
    return 0;
}
