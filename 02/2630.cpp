#include <stdio.h>

struct st {
    int w, b;
    st(int w,int b){this->w=w;this->b=b;}
    st operator+(const st &i) {return {i.w+w, i.b+b};}
};

int n, a[130][130];

st f(int x, int y, int w, int h)
{
    int first = a[x][y];
    for(int i=x; i<x+w; i++)
        for(int j=y; j<y+h; j++)
            if(a[i][j] != first)
                return f(x,y,w/2,h/2)+f(x+w/2,y,w/2,h/2)+f(x,y+h/2,w/2,h/2)+f(x+w/2,y+h/2,w/2,h/2);
    return first? st(0,1) : st(1,0);
}

int main()
{
	scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    st res = f(0,0,n,n);
    printf("%d %d", res.w, res.b);
}
