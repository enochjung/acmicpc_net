#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <vector>
#define N 500000

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

int n;
int cnt[N];

int main()
{
	scanf("%d", &n);
	polynomial a(n,0), b(n,0), res;

	for (int i=1; i<n; ++i)
		++cnt[1LL*i*i%n];
	for (int i=0; i<n; ++i)
		a[i] = b[i] = cnt[i];

	res = FFT::mul(a, b);

	long long ans1 = 0;
	long long ans2 = 0;
	for (int i=0; i<n; ++i)
		ans1 += cnt[i] * (FFT::get_integer(res[i]) + FFT::get_integer(res[n+i]));
	for (int i=1; i<n; ++i)
		ans2 += cnt[2LL*i*i%n];
	printf("%lld\n", (ans1-ans2)/2+ans2);
	return 0;
}