#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct team
{
    int id, total, submit, last;
    bool operator<(const team &i) const {
        return total!=i.total? total>i.total : submit!=i.submit? submit<i.submit : last<i.last;
    }
};

int t, n, k, y, m;

int main()
{
    for(scanf("%d",&t); t--;)
    {
        vector<team> a;
        int score[110][110] = {};
        
        scanf("%d %d %d %d", &n, &k, &y, &m);
        
        for(int i=1; i<=n; i++)
            a.push_back({i, 0, 0, 0});
        for(int i=1; i<=m; i++)
        {
            int q, w, e;
            scanf("%d %d %d", &q, &w, &e);
            q--, w--;
            score[q][w] = max(score[q][w], e);
            a[q].submit++;
            a[q].last = i;
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<k; j++)
                a[i].total += score[i][j];
        
        sort(a.begin(), a.end());
        
        for(int i=0; i<n; i++)
            if(a[i].id == y)
            {
                printf("%d\n", i+1);
                break;
            }
    }
    
    return 0;
}
