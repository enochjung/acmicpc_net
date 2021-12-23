#include <cstdio>

long long pow(long long a, long long b)
{
	long long res = 1;
	for (; b; a*=a,b>>=1)
		if (b & 1)
			res *= a;
	return res;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	while (a % b)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}
	return b;
}

long long f(int n)
{
	long long res = 0;
	for (int i=0; i<n; ++i)
		res += pow(3, gcd(n,i));
	if (n%2 == 0)
		res += (pow(3,n/2+1)+pow(3,n/2)) * (n/2);
	else
		res += pow(3, (n+1)/2)*n;
	return res / (n*2);
}

int main()
{
	int n;
	
	while (true)
	{
		scanf("%d", &n);
		if (n == -1)
			break;
		printf("%lld\n", f(n));
	}

	return 0;
}