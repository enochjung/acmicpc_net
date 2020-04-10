#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int t, c, m;

int main()
{
    for(scanf("%d",&t); t--;)
    {
        int res = 0;
        bool visited[100010] = {};
        queue<pair<int,int>> q;
        vector<pair<int,int>> v[100010];
        
        scanf("%d %d", &c, &m);
        for(int i=0; i<c-1; i++)
        {
            int c1, c2, d;
            scanf("%d %d %d", &c1, &c2, &d);
            c1--, c2--;
            v[c1].push_back({c2, d});
            v[c2].push_back({c1, d});
        }
        
        q.push({0, 0});
        while(!q.empty())
        {
            int x = q.front().first;
            int d = q.front().second;
            q.pop();
            
            visited[x] = true;
            if(res < d) res = d;
            
            int size = (int)v[x].size();
            for(int i=0; i<size; i++)
            {
                int to = v[x][i].first;
                int cost = v[x][i].second;
                
                if(!visited[to])
                    q.push({to, d+cost});
            }
        }
        
        printf("%d\n", res>=m? res : -1);
    }
    return 0;
}
