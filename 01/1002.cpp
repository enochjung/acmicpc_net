#include <stdio.h>

int t;

int distance(int p[]) {
    return (p[0]-p[3])*(p[0]-p[3]) + (p[1]-p[4])*(p[1]-p[4]);
}

int answer(int p[])
{
    if(p[0]==p[3] && p[1]==p[4] && p[2]==p[5]) return -1;
    
    int dis = distance(p);
    int r1 = (p[2]-p[5])*(p[2]-p[5]);
    int r2 = (p[2]+p[5])*(p[2]+p[5]);
    
    if(dis==r1 || dis==r2) return 1;
    if(r1<dis && dis<r2) return 2;
    return 0;
}

int main()
{
    for(scanf("%d", &t); t--;)
    {
        int p[6];
        for(int i=0; i<6; i++)
            scanf("%d", p+i);
        printf("%d\n", answer(p));
    }
}
