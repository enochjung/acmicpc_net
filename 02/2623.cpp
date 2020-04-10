#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
bool visited[1010], processed[1010], child[1010];
vector<int> v[1010], res;

bool f(int k)
{
    visited[k] = true;
    for(int i=0; i<v[k].size(); i++) {
        if(!processed[v[k][i]] && visited[v[k][i]])
            return true;
        else if(!visited[v[k][i]])
            if(f(v[k][i]))
                return true;
    }
    processed[k] = true;
    res.push_back(k);
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    while(m--) {
        int k, now;
        scanf("%d %d", &k, &now);
        while(--k) {
            int to;
            scanf("%d", &to);
            v[now].push_back(to);
            now = to;
            child[to] = true;
        }
    }
    
    for(int i=1; i<=n; i++)
        if(!child[i])
            v[0].push_back(i);
    
    if(f(0))
        return printf("0");
    
    for(int i=n-1; i>=0; i--)
        printf("%d\n", res[i]);
}
