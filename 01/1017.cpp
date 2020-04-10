#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> a, b;
int q[30];
bool visited[30], adj[30][30];

bool not_prime[2010];
vector<int> res;

bool dfs(int i, int ex)
{
    visited[i] = true;
    for(int j=0; j<n; j++)
        if(adj[i][j] && j!=ex && (q[j] == -1 || (!visited[q[j]] && dfs(q[j], ex)))) {
            q[j] = i;
            return true;
        }
    return false;
}

bool bipartite_matching(int ex)
{
    memset(q, -1, sizeof(q));
    
    for(int i=1; i<n; i++) {
        memset(visited, false, sizeof(visited));
        if(!dfs(i, ex)) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for(int i=0, f_odd=0, v; i<n; i++) {
        scanf("%d", &v);
        if(i==0) f_odd = v&1;
        (f_odd==(v&1)? a:b).push_back(v);
    }
    
    if(a.size() != b.size()) return printf("-1");
    n /= 2;
    
    for(int i=2; i<45; i++)
        if(!not_prime[i])
            for(int j=i*2; j<=2000; j+=i)
                not_prime[j] = true;
    
    for(int i=1; i<n; i++)
        for(int j=0; j<n; j++)
            if(!not_prime[a[i]+b[j]])
                adj[i][j] = true;
    
    for(int j=0; j<n; j++)
        if(!not_prime[a[0]+b[j]] && bipartite_matching(j))
            res.push_back(b[j]);
    
    int size = (int)res.size();
    if(size == 0) return printf("-1");
    sort(res.begin(), res.end());
    for(int i=0; i<size; i++)
        printf("%d ", res[i]);
}
