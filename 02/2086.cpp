#include <cstdio>
#include <vector>
#define R 1000000000

using namespace std;

long long a, b;

class matrix
{
public:
	matrix(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
	void multiply(matrix &i)
	{
		long long m1 = a*i.a + b*i.c;
		long long m2 = a*i.b + b*i.d;
		long long m3 = c*i.a + d*i.c;
		long long m4 = c*i.b + d*i.d;

		a = m1%R;
		b = m2%R;
		c = m3%R;
		d = m4%R;
	}
	void operator=(const matrix &i)
	{
		a = i.a;
		b = i.b;
		c = i.c;
		d = i.d;
	}
	long long get()
	{
		return d;
	}

private:
	long long a, b, c, d;
};

matrix f(long long x)
{
	matrix m(1, 1, 1, 0);

	if(x > 1)
	{
		matrix t = f(x/2);
		m = t;
		m.multiply(t);

		if(x & 1)
		{
			matrix v(1, 1, 1, 0);
			m.multiply(v);
		}
	}
	return m;
}

int main()
{
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", (f(b+3).get()-f(a+2).get()+R)%R);
	return 0;
}
