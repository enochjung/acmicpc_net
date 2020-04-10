#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n, m, cnt;
bool v[110];
vector<int> u[110], l[110];

int upper(int k)
{
    v[k] = true;
    int sum = 0;
    for(int i=0; i<u[k].size(); i++)
        if(!v[u[k][i]])
              sum += upper(u[k][i])+1;
    return sum;
}

int lower(int k)
{
    v[k] = true;
    int sum = 0;
    for(int i=0; i<l[k].size(); i++)
        if(!v[l[k][i]])
            sum += lower(l[k][i])+1;
    return sum;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        u[a].push_back(b);
        l[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++) {
        memset(v, 0, sizeof(v));
        if(upper(i)>(n-1)/2)
            cnt++;
        else {
            memset(v, 0, sizeof(v));
            if(lower(i)>(n-1)/2)
                cnt++;
        }
    }
    printf("%d", cnt);
}
