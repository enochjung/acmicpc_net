#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <vector>

using namespace std;
using C = complex<double>;
using polynomial = vector<C>;

int n;

class FFT
{
private:
	static void DFT(polynomial& dst, const C& w)
	{
		int n = dst.size();
		if(n == 1)
			return;

		polynomial even(n/2), odd(n/2);
		for(int i=0; i<n; i+=2)
		{
			even[i/2] = dst[i];
			odd[i/2] = dst[i+1];
		}

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
	static void mul(polynomial& a, polynomial& b, polynomial& res)
	{
		int n = 1;
		for(; n<=(int)max(a.size(),b.size()); n<<=1);
		a.resize(n), b.resize(n), res.resize(n);

		DFT(a), DFT(b);

		for(int i=0; i<n; ++i) {
			res[i] = a[i]*b[i];
		}

		DFT(res, true);
	}

	static long long get_integer(const C& c)
	{
		return (long long)(c.real()+0.5);
	}
};

int main()
{
	scanf("%d", &n);
	polynomial a(n,0), b(n,0), res;
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		a[i] = v;
	}
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		b[n-i-1] = v;
	}

	FFT::mul(a, b, res);

	long long ans = FFT::get_integer(res[n-1]);
	for (int i=0; i<n-1; ++i)
		ans = max(ans, FFT::get_integer(res[i])+FFT::get_integer(res[n+i]));
	printf("%lld", ans);
	return 0;
}
