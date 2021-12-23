#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <complex>
#include <vector>
#define N 300001

using namespace std;
using C = complex<double>;
using polynomial = vector<C>;

class FFT
{
private:
	static void DFT(polynomial& dst, const C& w)
	{
		int n = dst.size();
		if(n == 1)
			return;

		polynomial even(n/2), odd(n/2);
		for (int i=0; i<n; ++i)
			(i&1? odd : even)[i/2] = dst[i];

		DFT(even, w*w);
		DFT(odd, w*w);

		C wi(1, 0);

		for(int i=0; i<n/2; ++i,wi*=w)
		{
			dst[i] = even[i]+wi*odd[i];
			dst[i+n/2] = even[i]-wi*odd[i];
		}
	}

	static void DFT(polynomial& p, bool reverse=false)
	{
		int n = p.size();
		double base = (2*acos(-1))/n;
		if(reverse)
			base *= -1;
		C w(cos(base), sin(base));

		DFT(p, w);

		if(reverse)
			for(int i=0; i<n; ++i)
				p[i] /= (double)n;
	}

public:
	static polynomial mul(polynomial& a, polynomial& b)
	{
		int n = 1;
		for(; n<=(int)max(a.size(),b.size()); n<<=1);
		n <<= 1;
		a.resize(n);
		b.resize(n);
		polynomial res(n);

		DFT(a);
		DFT(b);

		for(int i=0; i<n; ++i)
			res[i] = a[i]*b[i];

		DFT(res, true);

		return res;
	}

	static long long get_integer(const C& c)
	{
		return (long long)(c.real()+0.5);
	}
};

char a[N], b[N];
int res_val[N*2];

int main()
{
	scanf("%s %s", a, b);
	
	int a_len = (int)strlen(a);
	int b_len = (int)strlen(b);
	int n = max(a_len, b_len);

	polynomial av(n,0), bv(n,0), res;
	for(int i=0; i<a_len; ++i)
		av[a_len-i-1] = a[i] - '0';
	for(int i=0; i<b_len; ++i)
		bv[b_len-i-1] = b[i] - '0';

	res = FFT::mul(av, bv);
	for (int i=0; i<n*2-1; ++i)
		res_val[i] = FFT::get_integer(res[i]);
	for (int i=0; i<n*2-2; ++i)
		if (res_val[i] >= 10)
		{
			res_val[i+1] += res_val[i]/10;
			res_val[i] %= 10;
		}
	
	bool print = false;
	for (int i=n*2-2; i>=0; --i)
	{
		if (res_val[i] != 0)
			print = true;
		if (print)
			printf("%d", res_val[i]);
	}
	if (!print)
		printf("0");
	printf("\n");
	return 0;
}
