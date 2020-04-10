#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

int n;
char a[40][40];
vector<int> res;

int f(int x, int y)
{
	int sum = 1;

	a[x][y] = '0';
	for(int k=0; k<4; k++)
	{
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(0<=nx && nx<n && 0<=ny && ny<n && a[nx][ny]=='1')
			sum += f(nx, ny);
	}
	return sum;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%s", a[i]);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(a[i][j] == '1')
				res.push_back(f(i, j));

	sort(res.begin(), res.end());

	printf("%d\n", (int)res.size());
	for(int i=0; i<(int)res.size(); i++)
		printf("%d\n", res[i]);
	return 0;
}
