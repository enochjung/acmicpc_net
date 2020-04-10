#include <stdio.h>

int n;
int x1[1010], y1[1010], x2[1010], y2[1010];
int p[1010];

bool hit(int i, int j)
{
	if(x1[i]>x2[j] || x2[i]<x1[j] || y1[i]>y2[j] || y2[i]<y1[j]) return false;
	if(x1[i]<x1[j] && x2[i]>x2[j] && y1[i]<y1[j] && y2[i]>y2[j]) return false;
	if(x1[i]>x1[j] && x2[i]<x2[j] && y1[i]>y1[j] && y2[i]<y2[j]) return false;
	return true;
}

int find(int i)
{
	return i==p[i]? i : p[i]=find(p[i]);
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d %d %d %d", x1+i, y1+i, x2+i, y2+i);

	for(int i=0; i<=n; i++)
		p[i] = i;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<=n; j++)
			if(hit(i,j))
			{
				int a = find(i);
				int b = find(j);
				if(a<b) p[b]=a;
				if(a>b) p[a]=b;
			}

	int res = 0;
	for(int i=1; i<=n; i++)
		if(i == p[i])
			res++;
	printf("%d", res);
	return 0;
}
