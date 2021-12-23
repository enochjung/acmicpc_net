#include <cstdio>
#include <cstring>
#define N 20
#define T 100
#define R 1000000007

class matrix
{
private:
	int size;
	int mat[N][N];

public:
	matrix operator*(const matrix &rhs) const
	{
		matrix result;
		result.resize(size);

		for (int i=0; i<size; ++i)
			for (int j=0; j<size; ++j)
			{
				int sum = 0;
				for (int k=0; k<size; ++k)
					sum = (sum + 1LL * mat[i][k] * rhs.get_value(k, j)) % R;
				result.set_value(i, j, sum);
			}

		return result;
	}

	matrix& operator*=(const matrix &rhs)
	{
		return *this = *this * rhs;
	}

	matrix()
	{
		memset(mat, 0, sizeof(mat));
	};

	void resize(int size)
	{
		this->size = size;
	}

	void set_value(int i, int j, int value)
	{
		mat[i][j] = value;
	}

	int get_value(int i, int j) const
	{
		return mat[i][j];
	}

	matrix power(int exponent) const
	{
		matrix result;
		result.resize(size);
		for (int i=0; i<size; ++i)
			result.set_value(i, i, 1);

		matrix base = *this;
		while (exponent)
		{
			if (exponent & 1)
				result *= base;
			base *= base;
			exponent >>= 1;
		}

		return result;
	}
};

int main()
{
	int t, n, d;
	matrix map[T], result;

	scanf("%d %d %d", &t, &n, &d);

	result.resize(n);
	for (int i=0; i<n; ++i)
		result.set_value(i, i, 1);

	for (int i=0; i<t; ++i)
	{
		int m;
		scanf("%d", &m);
		map[i].resize(n);

		while (m--)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			map[i].set_value(a-1, b-1, c);
		}

		result *= map[i];
	}

	result = result.power(d/t);
	for (int i=0; i<d%t; ++i)
		result *= map[i];

	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<n; ++j)
			printf("%d ", result.get_value(i, j));
		printf("\n");
	}
	return 0;
}