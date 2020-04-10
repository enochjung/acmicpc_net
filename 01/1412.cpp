#include <cstdio>
#define N 110

using namespace std;

int n;
char a[N][N];
bool visited[N], finished[N];
 
bool f(int i)
{
	visited[i] = true;

	for(int j=0; j<n; ++j)
		if(a[i][j]=='Y' && (i==j || a[j][i]!='Y'))
		{
			if(!visited[j])
			{
				if(!f(j))
					return false;
			}
			else if(!finished[j])
				return false;
		}

	finished[i] = true;
	return true;
}
 
int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf(" %s", a[i]);

	for(int i=0; i<n; ++i)
		if(!visited[i])
			if(!f(i))
			{
				printf("NO");
				return 0;
			}
	
	printf("YES");
	return 0;
}
