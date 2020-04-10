#include <cstdio>
#include <vector>
#define N 60

using namespace std;

int n, m, a[N], b[100][N];

int f(int* h)
{
	int r1=0, r2=0;
	int v1[16]={}, v2[16]={};
	for(int i=0; i<n; ++i)
		++v1[(h[i]-1)*4+(h[(i+1)%n]-1)];
	for(int i=n; i>0; --i)
		++v2[(h[i%n]>2?h[i%n]-3:h[i%n]+1)*4+(h[i-1]>2?h[i-1]-3:h[i-1]+1)];
	for(int i=0; i<16; ++i)
		r1 = (r1*2017+v1[i])%99991;
	for(int i=0; i<16; ++i)
		r2 = (r2*2017+v2[i])%99991;
	return r1^r2;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);
	scanf("%d", &m);
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			scanf("%d", &b[i][j]);

	vector<int*> v;
	int h = f(a);
	for(int i=0; i<m; ++i)
		if(f(b[i]) == h)
			v.push_back(b[i]);

	printf("%d\n", (int)v.size());
	for(int* t : v)
	{
		for(int i=0; i<n; ++i)
			printf("%d ", t[i]);
		printf("\n");
	}
	return 0;
}
