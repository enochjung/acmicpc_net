#include <cstdio>
#include <cstdlib>
#define R 1000000007

using namespace std;

int n, m, k;
long long seg[2097160];

class segment
{
private:
	int start;

public:
	segment(int size)
	{
		for(start=1; start<size; start<<=1);
	}

	void update(int x, long long value)
	{
		x += start;
		seg[x] = value;

		while(x > 1)
		{
			x >>= 1;
			seg[x] = (seg[x<<1]*seg[(x<<1)+1]) % R;
		}
	} 

	int find(int p, int q, int x=1, int left=0, int right=-1)
	{
		if(right == -1)
			right = start;
		if(p<=left && right<=q)
			return seg[x];
		if(right<=p || q<=left)
			return 1;
		int mid = (left+right)/2;
		return 1LL*find(p,q,x<<1,left,mid)*find(p,q,(x<<1)+1,mid,right) % R;
	}
};

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	segment s(n);
	for (int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		s.update(i, v);
	}
	for (int i=0; i<m+k; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1)
			s.update(b-1, c);
		else
			printf("%d\n", s.find(b-1, c));
	}
	return 0;
}
