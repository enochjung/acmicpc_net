#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

struct person
{
    int t;
    bool s;
    int no;
    
    bool operator<(const person &i) const
    {
        return t < i.t;
    }
};

int n;
person p[200010];
priority_queue<int,vector<int>,greater<int>> q;
int d[100010], res, cnt[100010];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        
        p[i*2] = {t1, true, i};
        p[i*2+1] = {t2, false, i};
        q.push(i);
    }
    
    sort(p, p+n*2);
    
    for(int i=0; i<n*2; i++)
    {
        person &a = p[i];
        
        if(a.s)
        {
            int c = q.top();
            q.pop();
            
            d[a.no] = c;
            cnt[c]++;
            res = max(res, c+1);
        }
        else
        {
            q.push(d[a.no]);
        }
    }
    
    printf("%d\n", res);
    for(int i=0; i<res; i++)
        printf("%d ", cnt[i]);
    return 0;
}
