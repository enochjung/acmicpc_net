#include <stdio.h>
#include <algorithm>

using namespace std;

struct st
{
	int x1, y1, x2, y2, px, py;
	int t;
} a[30];

int t, r, c, k;
int wx[5]={0,-1,0,1,0}, wy[5]={0,0,-1,0,1};


int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d %d %d", &r, &c, &k);
		for(int i=0; i<k; i++)
		{
			int x1, y1, x2, y2, px, py;
			scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &px, &py);

			a[i].x1=x1, a[i].y1=y1, a[i].x2=x2, a[i].y2=y2, a[i].px=px, a[i].py=py;
			a[i].t = min(px>0? (r-1-x2)/px : (px<0? x1/-px : 999), py>0? (c-1-y2)/py : (py<0? y1/-py : 999));
		}

		int res = 0;
		bool q[20][20][50] = {};
		q[0][0][0] = 1;

		for(int w=0; w<50 && !res; w++)
		{
			bool ch[20][20] = {};
			for(int i=0; i<r && !res; i++)
				for(int j=0; j<c && !res; j++)
					if(q[i][j][w])
						for(int l=0; l<5 && !res; l++)
						{
							int tx = i+wx[l];
							int ty = j+wy[l];

							if(0<=tx && tx<r && 0<=ty && ty<c && !ch[tx][ty])
							{
								bool hit = false;
								ch[tx][ty] = true;
								for(int m=0; m<k && !hit; m++)
								{
									int mt = min(w+1, a[m].t);
									int x1 = a[m].x1 + a[m].px*mt;
									int y1 = a[m].y1 + a[m].py*mt;
									int x2 = a[m].x2 + a[m].px*mt;
									int y2 = a[m].y2 + a[m].py*mt;

									if(x1<=tx && tx<=x2 && y1<=ty && ty<=y2)
										hit = true;
								}
								if(!hit)
								{
									q[tx][ty][w+1] = true;
									if(tx == r-1 && ty == c-1)
										res = w+1;
								}
							}
						}
		}

		printf("%d\n", res? res : -1);
	}

	return 0;
}
