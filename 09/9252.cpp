#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int n, m, d[2][1010], e[1010][1010];
char a[1010], b[1010];

int main()
{
	scanf("%s %s", a, b);
	n = (int)strlen(a);
	m = (int)strlen(b);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			if(a[i] == b[j])
			{
				d[1-i&1][j+1] = d[i&1][j]+1;
				e[i][j] = 1;
			}
			else if(d[1-i&1][j] > d[i&1][j+1])
			{
				d[1-i&1][j+1] = d[1-i&1][j];
				e[i][j] = 2;
			}
			else
			{
				d[1-i&1][j+1] = d[i&1][j+1];
				e[i][j] = 3;
			}
		}

	printf("%d\n", d[n&1][m]);

	stack<char> res;
	for(int i=n-1,j=m-1; i>=0 && j>=0;)
	{
		switch(e[i][j])
		{
		case 1:
			res.push(a[i]);
			i--, j--;
			break;
		case 2:
			j--;
			break;
		case 3:
			i--;
			break;
		}
	}

	while(!res.empty())
	{
		printf("%c", res.top());
		res.pop();
	}
	return 0;
}
