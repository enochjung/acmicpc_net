#include <cstdio>

int n, a[1000010], b, c;
long long res;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	scanf("%d %d", &b, &c);

	res = n;
	for(int i=0; i<n; i++)
		if(a[i] > b)
			res += (a[i]-b+c-1)/c;
	printf("%lld\n", res);
	return 0;
}
