#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#define MAX 100010
#define INF 999999999

using namespace std;

int m, n, res;
int r[MAX], v;
map<int,int> e[MAX];

int main()
{
    scanf("%d %d", &m, &n);
    for(int i=1; i<=m; i++)
    {
        int d;
        scanf("%d", &d);
        e[0][i] = d;
        r[i] = i;
    }
    v = m+1;
    for(int i=0; i<n; i++)
    {
        int a, b;
        vector<int> p;
        
        scanf("%d", &a);
        for(int i=0; i<a; i++)
        {
            int d;
            scanf("%d", &d);
            p.push_back(d);
            
            e[r[d]][v] = INF;
            r[d] = v++;
            
        }
        scanf("%d", &b);
        
        for(int i=0; i<a; i++)
        {
            e[r[p[i]]][v] = INF;
            if(i < a-1)
            {
                e[r[p[i]]][r[p[i+1]]] = INF;
                e[r[p[i+1]]][r[p[i]]] = INF;
            }
        }
        e[v][v+1] = b;
        
        while(1)
        {
            int p[MAX];
            queue<int> q;
            
            memset(p, -1, sizeof(p));
            q.push(0);
            while(!q.empty() && p[v+1]==-1)
            {
                int x = q.front();
                q.pop();
                
                for(auto i=e[x].begin(); i!=e[x].end(); ++i)
                {
                    int to = i->first;
                    int cap = i->second;
                    if(cap>0 && p[to]==-1)
                    {
                        q.push(to);
                        p[to] = x;
                        if(to == v+1)
                            break;
                    }
                }
            }
            
            if(p[v+1] == -1)
                break;
            
            int m = INF;
            for(int i=v+1; i!=0; i=p[i])
                m = min(m, e[p[i]][i]);
            res += m;
            
            for(int i=v+1; i!=0; i=p[i])
            {
                e[p[i]][i] -= m;
                e[i][p[i]] += m;
            }
        }
        e[v].clear();
        e[v+1].clear();
        for(int i=1; i<=m; i++)
            e[r[i]][v] = 0;
    }
    
    printf("%d\n", res);
    return 0;
}
