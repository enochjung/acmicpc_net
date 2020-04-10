#include <cstdio>
#include <algorithm>
#include <list>
#define N 200010

using std::max;
using std::list;

int n, a[N];
long long b[N];

class remainder
{
private:
	struct st
	{
		long long p, q;
	};
	list<st> l;

public:
	void push(long long value, long long interval)
	{
		l.insert(l.end(), {value, interval});
	}

	long long get()
	{
		long long sum = 0;
		for(st &i : l)
			sum += i.p;
		return sum;
	}

	void update()
	{
		for(auto it=l.begin(); !l.empty()&&it!=l.end(); ++it)
		{
			it->p -= it->q;
			while(!l.empty() && it->p<=0)
			{
				if(it != l.begin())
				{
					long long tmp1 = it->p;
					long long tmp2 = it->q;
					--it;
					it->p += tmp1;
					it->q += tmp2;
					++it;
				}
				it = l.erase(it);
				--it;
				if(it!=l.begin())
					break;
			}
		}
	}
};

int main()
{
	remainder r;

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	int idx = n+1;
	long long res=0, sum=0;
	for(int i=n-1; i>=0; --i)
	{
		b[i] = a[i]+b[i+1];
		if(b[idx]-b[i] > 0)
		{
			r.push(max(0LL,sum), b[idx]-b[i]);
			idx = i;
			sum = 0;
		}
		sum -= b[idx]-b[i];
		r.update();
		res = max(res, sum+r.get());
	}

	printf("%lld", res);
    return 0;
}
