#include <cstdio>

struct point
{
	int r, c;
};

int abs(int x)
{
	return x > 0 ? x : -x;
}

bool in_bound(point p)
{
	if (p.r < 1 || 11 < p.r)
		return false;
	return 1 <= p.c && p.c <= 11 - abs(p.r - 6);
}

point move(point p, int d)
{
	point ret = p;

	if (d == 0)
		++ret.c;
	else if (d == 1)
	{
		if (ret.r < 6)
			++ret.r, ++ret.c;
		else
			++ret.r;
	}
	else if (d == 2)
	{
		if (ret.r < 6)
			++ret.r;
		else
			++ret.r, --ret.c;
	}
	else if (d == 3)
		--ret.c;
	else if (d == 4)
	{
		if (ret.r <= 6)
			--ret.r, --ret.c;
		else
			--ret.r;
	}
	else
	{
		if (ret.r <= 6)
			--ret.r;
		else
			--ret.r, ++ret.c;
	}
	return ret;
}

bool b[20][20];

int main()
{
	char r1, r2;
	int c1, c2;

	scanf(" %c%d %c%d", &r1, &c1, &r2, &c2);

	for (int i = 0; i < 6; ++i)
		for (point p = move({r1 - 'a' + 1, c1}, i); in_bound(p); p = move(p, i))
			b[p.r][p.c] = true;

	int res = 0;
	for (int i = 0; i < 6; ++i)
		for (point p = move({r2 - 'a' + 1, c2}, i); in_bound(p); p = move(p, i))
			if (b[p.r][p.c] == true)
				++res;

	printf("%d\n", res);
	return 0;
}