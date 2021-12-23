#include <cstdio>
#define R 1000000007
 
int n, m, c;
 
int pow(int a, int b)
{
	long long res = 1;
 
	while (b)
	{
		if (b & 1)
			res = (res * a) % R;
		a = (1LL*a*a) % R;
		b >>= 1;
	}
	return res;
}
 
int gcd(int a, int b)
{
	while (a%b)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}
	return b;
}
 
int one_side()
{
	return pow(c, n*n);
}
 
int main()
{
	scanf("%d %d %d", &n, &m, &c);
 
	int p = pow(one_side(), m); 
	for (int i=1; i<m; ++i)
		p = (0LL + p + pow(one_side(), gcd(m,i))) % R;
 
	printf("%d\n", (1LL*p*pow(m,R-2)) % R);
	return 0;
}