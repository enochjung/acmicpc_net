#include <cstdio>
#include <algorithm>
#define N 1000010

using namespace std;

int n, m;
int a[N*2], b[N*2];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i*2);

	int r=-1, p=-1;
	for(int i=0; i<n*2; ++i)
	{
		if(i <= r)
			b[i] = min(b[2*p-i], r-i);
		while(i-b[i]>0 && i+b[i]<n*2-1 && a[i-b[i]-1]==a[i+b[i]+1])
			++b[i];
		if(i+b[i] > r)
		{
			r = i+b[i];
			p = i;
		}
	}
	
	for(scanf("%d",&m); m--;)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		i = (i-1)*2;
		j = (j-1)*2;
		printf("%d\n", b[(i+j)/2]>=(j-i)/2);
	}

	return 0;
}
