#include <cstdio>
#define N 50

int n, w[N], h[N];

int f(int ww, int hh)
{
	int cnt = 0;
	
	for (int i=0; i<n; ++i)
		if (w[i]>ww && h[i]>hh)
			++cnt;
		
	return cnt+1;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d %d", w+i, h+i);
	
	for (int i=0; i<n; ++i)
		printf("%d ", f(w[i], h[i]));
	return 0;
}