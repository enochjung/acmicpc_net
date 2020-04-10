#include <cstdio>

int n=19, a[20][20];
int dx[]={1, 1, 0, -1}, dy[]={0, 1, 1, 1};

bool is_bound(int x, int y)
{
	return 0<=x && x<n && 0<=y && y<n;
}

bool is_same(int x, int y, int c)
{
	return is_bound(x, y) && a[x][y]==c;
}

bool omok(int x, int y)
{
	int c = a[x][y];
	
	for(int w=0; w<4; ++w)
	{
		if(is_same(x-dx[w],y-dy[w],c) || is_same(x+dx[w]*5,y+dy[w]*5,c))
			continue;
		bool flag = true;
		for(int i=1; i<5; ++i)
			if(!is_same(x+dx[w]*i, y+dy[w]*i, c))
				flag = false;
		if(flag)
			return true;
	}

	return false;
}

int main()
{
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			scanf("%d", &a[i][j]);

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(a[i][j])
				if(omok(i, j))
				{
					printf("%d\n%d %d", a[i][j], i+1, j+1);
					return 0;
				}

	printf("0");
	return 0;
}
