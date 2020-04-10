#include <cstdio>

int n, k;
int sum;

int main()
{
	scanf("%d %d", &n, &k);
	while(k--)
	{
		int v;
		scanf("%d", &v);
		sum += (v+1)/2;
	}
	
	printf("%s", sum>=n? "YES" : "NO");
	return 0;
}
