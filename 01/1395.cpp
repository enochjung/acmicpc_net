#include <cstdio>
#define N 1<<18

int n, m;
int start;
int v[N];
bool l[N];

void propagate(int idx, int width)
{
	if(l[idx])
	{
		if(idx < start)
		{
			l[idx*2] ^= 1;
			l[idx*2+1] ^= 1;
		}
		v[idx] = width-v[idx];
		l[idx] = 0;
	}
}

void update(int idx, int s, int e, int a, int b)
{
	propagate(idx, e-s);

	if(b<=s || e<=a)
		return;

	if(a<=s && e<=b)
	{
		l[idx] ^= 1;
		propagate(idx, e-s);
		return;
	}

	int mid = (s+e)/2;
	update(idx*2, s, mid, a, b);
	update(idx*2+1, mid, e, a, b);
	v[idx] = v[idx*2]+v[idx*2+1];
}

int get(int idx, int s, int e, int a, int b)
{
	propagate(idx, e-s);

	if(b<=s || e<=a)
		return 0;

	if(a<=s && e<=b)
		return v[idx];

	int mid = (s+e)/2;
	return get(idx*2, s, mid, a, b) + get(idx*2+1, mid, e, a, b);
}

int main()
{
	scanf("%d %d", &n, &m);
	start = N>>1;

	while(m--)
	{
		int o, s, t;
		scanf("%d %d %d", &o, &s, &t);

		if(o == 0)
			update(1, 0, start, s-1, t);
		else
			printf("%d\n", get(1, 0, start, s-1, t));
	}

	return 0;
}
