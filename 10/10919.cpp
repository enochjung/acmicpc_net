#include <cstdio>
#include <algorithm>
#define N 10000010

using namespace std;

int n, k, l, a[N];
long long adv[N];

pair<long long,int> calculate(int s1, int s2, int rem)
{
    long long sum = 0;
    for(int i=0; i<rem && s1-i>=0; ++i)
        sum += adv[s1-i];
    long long max_adv = sum;
    int max_idx = 0;
    
    for(int i=1; i<=rem; ++i)
    {
        sum -= (s1-(rem-i)>=0? adv[s1-(rem-i)] : 0);
        sum += (s2+i-1<n? adv[s2+i-1] : 0);
        if(max_adv < sum)
        {
            max_adv = sum;
            max_idx = i;
        }
    }
    
    return {max_adv*2, max_idx};
}

void remove(int &s1, int &s2, int rem, int idx)
{
    s1 = s1-(rem-idx)>=0? s1-(rem-idx) : -1;
    s2 = s2+idx<n? s2+idx : n;
}

int main()
{
    scanf("%d %d %d", &n, &k, &l);
    for(int i=0; i<n; ++i)
        scanf("%d", a+i);
    
    int s1, s2;
    for(s1=-1; s1+1<n && a[s1+1]<(l+1)/2; ++s1);
    for(s2=n; s2-1>=0 && a[s2-1]>l/2; --s2);
    
    for(int i=0; i<=s1; ++i)
        adv[i] = (i-k>=0?adv[i-k]:0)+a[i]-(i-1>=0?a[i-1]:0);
    for(int i=n-1; i>=s2; --i)
        adv[i] = (i+k<n?adv[i+k]:0)+(l-a[i])-(i+1<n?(l-a[i+1]):0);
    
    long long res = 0;
    
    pair<long long,int> ret;
    if(s1+1 < s2)
    {
        res += (s2-s1+k-2)/k*l;
        int rem = (k-(s2-s1-1)%k)%k;
        if(rem > 0)
        {
            ret = calculate(s1, s2, rem);
            remove(s1, s2, rem, ret.second);
        }
    }
    
    while((ret = calculate(s1, s2, k)).first > l)
    {
        res += l;
        remove(s1, s2, k, ret.second);
    }
    
    while(s1 >= 0)
    {
        res += a[s1]*2;
        s1 -= k;
    }
    while(s2 < n)
    {
        res += (l-a[s2])*2;
        s2 += k;
    }
    
    printf("%lld", res);
    return 0;
}
