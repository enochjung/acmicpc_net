#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct vote { int a[3]; };
struct score
{
    int a, b, c, d;
    bool operator<(const score &i) const {
        return b!=i.b? b>i.b : c!=i.c? c>i.c : d>i.d;
    }
};

int n, d;

int main()
{
    while(1)
    {
        map<int,vote> m;
        vector<score> v;
        
        scanf("%d", &n);
        if(n == 0) break;
        while(n--)
        {
            scanf("%d",&d);
            for(int i=0; i<d; i++)
            {
                int p;
                scanf("%d", &p);
                m[p].a[i]++;
            }
        }
        
        for(auto i=m.begin(); i!=m.end(); ++i)
        {
            int who = i->first;
            int first = i->second.a[0];
            int second = i->second.a[1];
            int third = i->second.a[2];
            
            v.push_back({who, first*3+second*2+third, first, second});
        }
        
        sort(v.begin(), v.end());
        
        int score = v[0].b;
        int first = v[0].c;
        int second = v[0].d;
        for(int i=0; i<(int)v.size() && v[i].b==score && v[i].c==first && v[i].d==second; i++)
            printf("%d ", v[i].a);
        printf("\n");
    }
    return 0;
}
