#include <cstdio>

int m, n;

int gcd(int a, int b)
{
	while(a%b)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}
	return b;
}

int main()
{
	scanf("%d %d", &m, &n);
	m = m>0? m : -m;
	n = n>0? n : -n;

	if(m==0 && n==0)
		printf("0");
	else if((m && n && gcd(m,n)==1) || (m==0 && n==1) || (m==1 && n==0))
		printf("1");
	else
		printf("2");
	return 0;
}
