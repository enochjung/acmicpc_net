#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 18
#define INF 999

using namespace std;

struct word
{
	char* s;
	int l;
};

int h, w, n;
vector<word> v;
int o[N][N], d[N][1<<N], p[N][1<<N];

void get_input()
{
	scanf("%d %d %d", &h, &w, &n);
	for (int i=0; i<n; ++i)
	{
		char* str = new char[N+1];
		scanf("%s", str);
		v.push_back((word){str, (int)strlen(str)});
		if (v[i].l > w)
		{
			printf("impossible\n");
			exit(0);
		}
	}
}

void remove_duplicate()
{
	bool remove[N] = {};

	sort(v.begin(), v.end(), [](word &lhs, word &rhs) { return lhs.l>rhs.l; });

	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (strstr(v[i].s, v[j].s) != NULL)
				remove[j] = true;

	vector<word> tmp;
	for (int i=0; i<n; ++i)
	{
		if (!remove[i])
			tmp.push_back(v[i]);
		else
			delete[] v[i].s;
	}
		
	v = tmp;
	n = v.size();
}

void set_overlap_array()
{
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			for (int k=min(v[i].l,v[j].l); k>0; --k)
			{
				bool flag = true;
				for (int w=0; w<k; ++w)
					if (v[i].s[v[i].l-k+w] != v[j].s[w])
					{
						flag = false;
						break;
					}
				if (flag)
				{
					o[i][j] = k;
					break;
				}
			}
}

int dp(int a, int b)
{
	if (1<<a == b)
		return v[a].l;
	if (d[a][b] == -1)
	{
		int bf = b^(1<<a);
		d[a][b] = INF;
		for (int i=0; i<n; ++i)
			if (i!=a && (1<<i)&b)
			{
				int pos = dp(i, bf);
				int st = pos%w;
				if (st == 0)
				{
					if (d[a][b] > pos+v[a].l)
					{
						d[a][b] = pos+v[a].l;
						p[a][b] = i;
					}
				}
				else
				{
					if (st+v[a].l-o[i][a] <= w)
					{
						if (d[a][b] > pos+v[a].l-o[i][a])
						{
							d[a][b] = pos+v[a].l-o[i][a];
							p[a][b] = i;
						}
					}
					else
					{
						if (d[a][b] > pos-st+w+v[a].l)
						{
							d[a][b] = pos-st+w+v[a].l;
							p[a][b] = i;
						}
					}
				}
			}
	}
	return d[a][b];
}

void print_answer(int x)
{
	vector<int> stack;

	for (int flag=(1<<n)-1; flag;)
	{
		int tmp = x;
		stack.push_back(x);
		x = p[x][flag];
		flag ^= 1<<tmp;
	}

	int sum_h = 0;
	int sum_w = 0;
	int before = -1;
	while (!stack.empty())
	{
		int i = stack.back();
		stack.pop_back();

		if (before!=-1 && sum_w+v[i].l-o[before][i]<=w)
		{
			for (int j=o[before][i]; j<v[i].l; ++j)
				putchar(v[i].s[j]);
			sum_w += v[i].l-o[before][i];
		}
		else
		{
			if (before != -1)
			{
				for (int j=sum_w; j<w; ++j)
					putchar('A');
				putchar('\n');
				++sum_h;
			}

			printf("%s", v[i].s);
			sum_w = v[i].l;
		}
		before = i;
	}
	for (int j=sum_w; j<w; ++j)
		putchar('A');
	putchar('\n');
	for (int i=sum_h+1; i<h; ++i)
	{
		for (int j=0; j<w; ++j)
			putchar('A');
		putchar('\n');
	}
}

void calculate()
{
	memset(d, -1, sizeof(d));

	for (int i=0; i<n; ++i)
		if (dp(i,(1<<n)-1) <= h*w)
		{
			print_answer(i);
			return;
		}
	printf("impossible\n");
}

int main()
{
	get_input();
	remove_duplicate();
	set_overlap_array();
	calculate();

	return 0;
}