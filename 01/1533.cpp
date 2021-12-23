#include <cstdio>
#include <vector>
#define N 10
#define R 1000003

using namespace std;
using matrix = vector<vector<long long>>;

int n, s, e;
long long t;

matrix operator*(const matrix &lhs, const matrix &rhs)
{
	matrix ret(n*5, vector<long long>(n*5));

	for (int i=0; i<n*5; ++i)
		for (int j=0; j<n*5; ++j)
			for (int k=0; k<n*5; ++k)
				ret[i][j] = (ret[i][j]+lhs[i][k]*rhs[k][j]) % R;

	return ret;
}

matrix pow(matrix m, long long b)
{
	matrix ret(n*5, vector<long long>(n*5));
	for (int i=0; i<n*5; ++i)
		ret[i][i] = 1;

	while (b)
	{
		if (b & 1)
			ret = ret*m;
		b >>= 1;
		m = m*m;
	}
	return ret;
}

int main()
{
	scanf("%d %d %d %lld", &n, &s, &e, &t);

	matrix m(n*5, vector<long long>(n*5));
	for (int i=0; i<n*5; ++i)
		if (i%5 != 4)
			m[i][i+1] = 1;

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
		{
			int val;
			scanf("%1d", &val);
			if (val > 0)
				m[i*5+4][j*5+5-val] = 1;
		}

	printf("%lld\n", pow(m,t)[s*5-1][e*5-1]);
	return 0;
}