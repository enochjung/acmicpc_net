#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n, t[510];
vector<int> v[510];
int d[510];

int f(int i)
{
	if(d[i] == -1)
	{
		int m=0, s=v[i].size();
		for(int j=0; j<s; j++)
		{
			int res = f(v[i][j]);
			if(m<res) m=res;
		}
		d[i] = t[i]+m;

	}
	return d[i];
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int s;
		scanf("%d", t+i);
		while(scanf("%d",&s),s!=-1)
			v[i].push_back(s-1);
	}

	memset(d, -1, sizeof(d));
	for(int i=0; i<n; i++)
		printf("%d\n", f(i));

	return 0;
}
