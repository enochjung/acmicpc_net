#include <cstdio>

int pow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
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

int f(int c, int s)
{
	int res = 0;
	for (int i=0; i<s; ++i)
		res += pow(c, gcd(s,i));
	if (s%2 == 0)
	{
		res += pow(c,s/2+1) * (s/2);
		res += pow(c,s/2) * (s/2);
	}
	else
		res += pow(c, (s+1)/2)*s;
	return res / (s*2);
}

int main()
{
	int c, s;
	
	while (true)
	{
		scanf("%d %d", &c, &s);
		if (c == 0)
			break;
		printf("%d\n", f(c,s));
	}

	return 0;
}