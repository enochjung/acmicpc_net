#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n;

long long a()
{
    if(n&1)
        return 1LL*(n-1)*(n-1)/4;
    return 1LL*n*(n-2)/4;
}

int b()
{
    set<int> s;
    vector<int> v;
    
    if(n&1)
        return 0;
    
    for(int i=1; i*i<=n; i++)
        if(n%i == 0)
        {
            s.insert(i);
            v.push_back(i);
            if(i*i != n)
            {
                s.insert(n/i);
                v.push_back(n/i);
            }
        }
    
    sort(v.begin(), v.end());
    
    int cnt = 0;
    for(int i=v.size()-1; i>0; i--)
        for(int j=0; v[j]*2<=v[i]; j++)
            if(s.find(v[i]-v[j]) != s.end())
                cnt++;
    
    return cnt;
}

int c()
{
    bool p[500010] = {1, 1};
    
    for(int i=2; i*i<=n; i++)
        if(!p[i])
            for(int j=i*2; j<=n; j+=i)
                p[j] = true;
    
    int cnt = 0;
    for(int i=n; i>=5; i--)
        if(!p[i] && !p[i-2])
            cnt++;
        
    return cnt;
}

int main()
{
    scanf("%d", &n);
    printf("%lld\n%d\n%d\n", a(), b(), c());
    return 0;
}
