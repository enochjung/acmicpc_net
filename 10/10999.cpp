#include <cstdio>
#define N 1<<21

long long v[N]={}, l[N]={};

class segment_tree
{
private:
	int start;

	void propagate(int idx, int width)
	{
		if(l[idx])
		{
			if(idx < start)
			{
				l[idx*2] += l[idx];
				l[idx*2+1] += l[idx];
			}
			v[idx] += l[idx]*width;
			l[idx] = 0;
		}
	}

	void add(int idx, int s, int e, int a, int b, int val)
	{
		propagate(idx, e-s);

		if(b<=s || e<=a)
			return;

		if(a<=s && e<=b)
		{
			l[idx] += val;
			propagate(idx, e-s);
			return;
		}

		int mid = (s+e)/2;
		add(idx*2, s, mid, a, b, val);
		add(idx*2+1, mid, e, a, b, val);
		v[idx] = v[idx*2]+v[idx*2+1];
	}

	long long sum(int idx, int s, int e, int a, int b)
	{
		propagate(idx, e-s);

		if(b<=s || e<=a)
			return 0;

		if(a<=s && e<=b)
			return v[idx];

		int mid = (s+e)/2;
		return sum(idx*2, s, mid, a, b) + sum(idx*2+1, mid, e, a, b);
	}

public:
	segment_tree(int size)
	{
		for(start=1; start<size; start<<=1);
	}

	void add(int a, int b, int val)
	{
		add(1, 1, start, a, b, val);
	}

	long long sum(int a, int b)
	{
		return sum(1, 1, start, a, b);
	}
};

int n, m, k;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	segment_tree s(n);

	for(int i=0; i<n; ++i)
	{
		int a;
		scanf("%d", &a);
		s.add(i+1, i+2, a);
	}

	for(int i=0; i<m+k; ++i)
	{
		int a, b, c, d;
		scanf("%d", &a);
		if(a == 1)
		{
			scanf("%d %d %d", &b, &c, &d);
			s.add(b, c+1, d);
		}
		else
		{
			scanf("%d %d", &b, &c);
			printf("%lld\n", s.sum(b, c+1));
		}
	}

	return 0;
}
