#include <cstdio>
#include <vector>
#define R 1000000007

using namespace std;

int d;

class matrix
{
private:
	vector<vector<int>> a;
	
public:
	matrix(int n, vector<vector<int>> m)
	{
		a.resize(n);
		for(int i=0; i<n; ++i)
			a[i].resize(n);
		a = m;
	}

	void multiply(matrix &m)
	{
		vector<vector<int>> copy;
		copy.assign(a.begin(), a.end());

		int n = a.size();
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				long long cnt = 0;
				for(int k=0; k<n; ++k)
					cnt += 1LL*copy[i][k]*m.get(k,j);
				a[i][j] = cnt%R;
			}
	}

	void operator=(const matrix &m)
	{
		int n = m.size();
		a.resize(n);
		for(int i=0; i<n; ++i)
			a[i].resize(n);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				a[i][j] = m.get(i,j);
	}

	int get(int i, int j) const
	{
		return a[i][j];
	}

	int size() const
	{
		return a.size();
	}
};

matrix f(long long x)
{
	matrix m(8, {
			{0,1,0,0,0,1,0,0},
			{1,0,1,0,0,1,0,0},
			{0,1,0,1,0,1,1,0},
			{0,0,1,0,1,0,1,0},
			{0,0,0,1,0,0,0,1},
			{1,1,1,0,0,0,1,0},
			{0,0,1,1,0,1,0,1},
			{0,0,0,0,1,0,1,0},
			});

	if(x > 1)
	{
		matrix t = f(x/2);
		m = t;
		m.multiply(t);

		if(x & 1)
		{
			matrix v(8, {
			{0,1,0,0,0,1,0,0},
			{1,0,1,0,0,1,0,0},
			{0,1,0,1,0,1,1,0},
			{0,0,1,0,1,0,1,0},
			{0,0,0,1,0,0,0,1},
			{1,1,1,0,0,0,1,0},
			{0,0,1,1,0,1,0,1},
			{0,0,0,0,1,0,1,0},
			});
			m.multiply(v);
		}
	}
	return m;
}

int main()
{
	scanf("%d", &d);
	printf("%d", f(d).get(0,0));
	return 0;
}
