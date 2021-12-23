#include <cstdio>
#define N 1001

int n;
char a[N], b[N];
int p[10], q[10];

bool must_pop(int i)
{
	return p[a[i]-'0'] == q[a[i]-'0'];
}

int can_pop(int i, int v)
{
	int t[10];
	for (int i=0; i<10; ++i)
		t[i] = q[i];

	for (; i<n; ++i)
	{
		if (a[i]-'0'>v && !must_pop(i))
			break;
		if (t[a[i]-'0'] == 0)
			return -1;
		--t[a[i]-'0'];
	}
	return i;
}

void pop(int i, int j)
{
	for (; i<j; ++i)
	{
		--p[a[i]-'0'];
		--q[a[i]-'0'];
		a[i] = 0;
	}
}

int main()
{
	scanf("%s %s", a, b);
	for (n=0; a[n]; ++n)
		++p[a[n]-'0'];
	for (int i=0; b[i]; ++i)
		++q[b[i]-'0'];

	for (int i=0; i<n; ++i)
	{
		int idx = can_pop(i, a[i]-'0');

		if (idx > i)
		{
			pop(i, idx);
			i = idx-1;
		}
		else if (must_pop(i))
			pop(i, i+1);
		else
			--p[a[i]-'0'];
	}

	bool zero = true;
	for (int i=0; i<n; ++i)
		if (a[i] >= '0')
		{
			if (a[i] >= '1')
				zero = false;
			if (!zero)
				printf("%c", a[i]);
		}
	printf("\n");
	return 0;
}