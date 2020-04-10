#include <cstdio>
#include <map>
#include <vector>
#define M 1010

using namespace std;

int m;
int q[100010], v[M], idx, res;
vector<int> p, e[M];
map<int,int> to;

void init()
{
    bool np[10010] = {};
    for(int i=2; i<=10000; ++i)
        if(!np[i])
        {
            p.push_back(i);
            for(int j=i*i; j<=10000; j+=i)
                np[j] = true;
        }
}

void edge(int v, int i)
{
    for(int pr : p)
        if(v%pr == 0)
        {
            if(to.find(pr) == to.end())
                to.insert({pr, ++idx});
            e[i].push_back(to[pr]);
            while(v%pr == 0)
                v /= pr;
        }
    if(v > 1)
    {
        if(to.find(v) == to.end())
            to.insert({v, ++idx});
        e[i].push_back(to[v]);
    }
}

bool f(int x, int lv)
{
    v[x] = lv;
    
    for(int y : e[x])
        if(q[y]==0 || (v[q[y]]<lv && f(q[y],lv)))
        {
            q[y] = x;
            return true;
        }
    return false;
}

int main()
{
    init();
    
    scanf("%*d %d", &m);
    for(int i=1; i<=m; ++i)
    {
        int v;
        scanf("%d", &v);
        edge(v, i);
        if(f(i, i))
            ++res;
    }
    printf("%d", res);
    return 0;
}
