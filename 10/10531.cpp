
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <vector>
#define MAX_VALUE 200000

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

int n, m;

int main()
{
	scanf("%d", &n);
	polynomial a(MAX_VALUE+1,0), b(MAX_VALUE+1,0), res;
	a[0] = b[0] = 1;
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		a[v] = b[v] = 1;
	}

	res = FFT::mul(a, b);

	int ans = 0;
	scanf("%d", &m);
	for (int i=0; i<m; ++i)
	{
		int v;
		scanf("%d", &v);
		if (FFT::get_integer(res[v]) > 0)
			++ans;
	}
	printf("%d\n", ans);
	return 0;
}
