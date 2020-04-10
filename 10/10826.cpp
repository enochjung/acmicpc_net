#include <cstdio>
#define SIZE 200

class big_int
{
public:
	big_int()
	{
		for(int i =0; i<SIZE; i++)
			v[i] = 0;
	}
	big_int& operator+=(const big_int &t)
	{
		for(int i=0; i<SIZE; i++)
		{
			v[i] = v[i]+t.get(i);
			if(i+1 < SIZE)
				v[i+1] += v[i]/r;
			v[i] %= r;
		}
		return *this;
	}
	big_int operator+(const big_int &t)
	{
		big_int res = *this;
		res += t;
		return res;
	}
	big_int& operator=(const int t)
	{
		v[0] = t;
		return *this;
	}
	big_int& operator=(const big_int &t)
	{
		for(int i=0; i<SIZE; i++)
			v[i] = t.get(i);
		return *this;
	}
	void print()
	{
		bool start = false;
		for(int i=SIZE-1; i>=0; i--)
		{
			if(start)
			{
				printf("%018lld", v[i]);
			}
			if((v[i]!=0 || i==0) && !start)
			{
				start = true;
				printf("%lld", v[i]);
			}
		}
	}
	long long get(int i) const
	{
		return v[i];
	}

private:
	const long long r = 1000000000000000000L;
	long long v[SIZE];
};

int n;
big_int d[10010];

int main()
{
	scanf("%d", &n);

	d[0] = 0;
	d[1] = 1;
	for(int i=2; i<=n; i++)
		d[i] = d[i-1]+d[i-2];

	d[n].print();
	printf("\n");
	return 0;
}
