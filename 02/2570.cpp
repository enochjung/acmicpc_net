#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX 10010

using namespace std;

int n, m;
int q[MAX], v[MAX], t[110][110];
vector<int> e[MAX];

bool f(int x, int lv)
{
	v[x] = lv;

	for(int y : e[x])
		if(q[y]==-1 || (v[q[y]]<lv && f(q[y],lv)))
		{
			q[y] = x;
			return true;
		}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	while(m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		t[a-1][b-1] = -1;
	}

	int num1=0, num2=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(t[i][j] == 0)
			{
				for(int k=0; i+k<n && j+k<n; k++)
				{
					if(t[i+k][j+k] == -1)
						break;
					t[i+k][j+k] = num1+1;
				}
				num1++;
			}

	for(int i=n-1; i>=0; i--)
		for(int j=0; j<n; j++)
			if(t[i][j] > 0)
			{
				for(int k=0; i-k>=0 && j+k<n; k++)
				{
					if(t[i-k][j+k] == -1)
						break;
					e[num2].push_back(t[i-k][j+k]-1);
					t[i-k][j+k] = 0;
				}
				num2++;
			}

	int res = 0;

	memset(q, -1, sizeof(q));
	for(int i=0; i<num2; i++)
		if(f(i, i+1))
			res++;

	printf("%d\n", res);
	return 0;
}
