#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

struct st
{
	int a, b, c;
} s[1010];

int n;
int q[1010], v[1010];
vector<int> e[1010];

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
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d %d", &s[i].a, &s[i].b, &s[i].c);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(s[i].a>=s[j].a && s[i].b>=s[j].b && s[i].c>=s[j].c)
				if(s[i].a>s[j].a || s[i].b>s[j].b || s[i].c>s[j].c || i<j)
				{
					e[i*2].push_back(j);
					e[i*2+1].push_back(j);
				}

	int res = 0;

	memset(q, -1, sizeof(q));
	for(int i=0; i<n*2; i++)
		if(f(i, i+1))
			res++;

	printf("%d\n", n-res);
	return 0;
}
