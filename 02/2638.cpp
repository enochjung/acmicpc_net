#include <stdio.h>
#include <list>
#define N 110

struct point {
    int x, y;
};

using namespace std;
typedef list<point> lp;

int n, m, t, c[N][N];
bool a[N][N];
int mx[4]={-1,0,1,0}, my[4]={0,-1,0,1};

lp cheese, air;

void set_air(int x, int y)
{
    a[x][y] = true;
    
    for(int i=0; i<4; i++) {
        int nx=x+mx[i], ny=y+my[i];
        if(0<=nx && nx<n && 0<=ny && ny<m && !c[nx][ny] && !a[nx][ny])
            set_air(nx, ny);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            cin >> c[i][j];
            if(c[i][j])
                cheese.push_back({i, j});
        }
    
    set_air(0, 0);
    
    while(!cheese.empty())
    {
        for(lp::iterator it=cheese.begin(); it!=cheese.end(); ++it) {
            int cnt = 0;
            for(int i=0; i<4; i++) {
                int nx=it->x+mx[i], ny=it->y+my[i];
                if(0<=nx && nx<n && 0<=ny && ny<m && a[nx][ny])
                    cnt++;
            }
            if(cnt>=2) {
                c[it->x][it->y] = false;
                air.push_back({it->x, it->y});
                cheese.erase(it--);
            }
        }
        
        for(lp::iterator it=air.begin(); it!=air.end(); ++it) {
            if(!a[it->x][it->y])
                set_air(it->x, it->y);
            air.erase(it--);
        }
        
        t++;
    }
    
    printf("%d", &t);
}
