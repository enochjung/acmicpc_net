#include <stdio.h>
#include <queue>

using namespace std;

struct st {
    int t;
    bool b[3][3], p[9];
};

int p;
int px[5]={0,-1,0,1,0}, py[5]={0,0,-1,0,1};
bool d[3][3];
queue<st> q;

int main()
{
    for(scanf("%d",&p); p--;)
    {
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++) {
                char c;
                scanf(" %c", &c);
                d[i][j] = c=='*';
            }
        
        q.push({});
        while(!q.empty())
        {
            int t = q.front().t;
            bool (*b)[3] = q.front().b;
            bool *p = q.front().p;
            
            bool check = true;
            for(int i=0; i<9; i++)
                if(b[i%3][i/3] != d[i%3][i/3]) {
                    check = false;
                    break;
                }
            if(check) {
                printf("%d\n", t);
                break;
            }
            
            for(int k=0; k<9; k++)
                if(!p[k]) {
                    q.push({t+1});
                    st &nq = q.back();
                    
                    for(int i=0; i<9; i++) {
                        nq.b[i%3][i/3] = b[i%3][i/3];
                        nq.p[i] = p[i];
                    }
                    nq.p[k] = true;
                    
                    for(int i=0; i<5; i++) {
                        int nx=k%3+px[i], ny=k/3+py[i];
                        if(0<=nx && nx<3 && 0<=ny && ny<3)
                            nq.b[nx][ny] = !nq.b[nx][ny];
                    }
                }
            q.pop();
        }
        
        while(!q.empty()) q.pop();
    }
}
