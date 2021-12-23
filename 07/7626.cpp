#include <cstdio>
#include <algorithm>
#include <vector>
#define N 200010
#define T (1 << 18)

using namespace std;

struct rect
{
	int x1, x2, y1, y2;
	void scan()
	{
		scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
	}
};

struct query
{
	int x, y1, y2;
	bool add;
	bool operator<(const query &i) const
	{
		return x < i.x;
	}
};

struct node
{
	int cnt;
	long long sum, size;
};

int n;
rect r[N];
vector<int> xd, yd;
vector<query> q;
node t[T << 1];

void x_compress()
{
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		v.push_back(r[i].x1);
		v.push_back(r[i].x2);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 1; i < v.size(); ++i)
		xd.push_back(v[i] - v[i - 1]);

	for (int i = 0; i < n; ++i)
	{
		r[i].x1 = (int)(lower_bound(v.begin(), v.end(), r[i].x1) - v.begin());
		r[i].x2 = (int)(lower_bound(v.begin(), v.end(), r[i].x2) - v.begin());
	}
}

void y_compress()
{
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		v.push_back(r[i].y1);
		v.push_back(r[i].y2);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 1; i < v.size(); ++i)
		yd.push_back(v[i] - v[i - 1]);

	for (int i = 0; i < n; ++i)
	{
		r[i].y1 = (int)(lower_bound(v.begin(), v.end(), r[i].y1) - v.begin());
		r[i].y2 = (int)(lower_bound(v.begin(), v.end(), r[i].y2) - v.begin());
	}
}

void make_query()
{
	for (int i = 0; i < n; ++i)
	{
		q.push_back({r[i].x1, r[i].y1, r[i].y2, true});
		q.push_back({r[i].x2, r[i].y1, r[i].y2, false});
	}
	sort(q.begin(), q.end());
}

void initialize_tree()
{
	for (int i = T << 1; i >= 1; --i)
	{
		if (i >= T)
		{
			int idx = i - T;
			t[i].size = idx < yd.size() ? yd[idx] : 0;
		}
		else
			t[i].size = t[i * 2].size + t[i * 2 + 1].size;
	}
}

long long get_size(int i)
{
	return t[i].cnt > 0 ? t[i].size : t[i].sum;
}

void add(int idx, int node_s, int node_e, int query_s, int query_e)
{
	if (query_e <= node_s || node_e <= query_s)
		return;
	if (query_s <= node_s && node_e <= query_e)
		++t[idx].cnt;
	else if (idx >= T)
		++t[idx].cnt;
	else
	{
		add(idx * 2, node_s, (node_s + node_e) / 2, query_s, query_e);
		add(idx * 2 + 1, (node_s + node_e) / 2, node_e, query_s, query_e);
		t[idx].sum = get_size(idx * 2) + get_size(idx * 2 + 1);
	}
}

void add(int y1, int y2)
{
	add(1, 0, T, y1, y2);
}

void remove(int idx, int node_s, int node_e, int query_s, int query_e)
{
	if (query_e <= node_s || node_e <= query_s)
		return;
	if (query_s <= node_s && node_e <= query_e)
		--t[idx].cnt;
	else if (idx >= T)
		--t[idx].cnt;
	else
	{
		remove(idx * 2, node_s, (node_s + node_e) / 2, query_s, query_e);
		remove(idx * 2 + 1, (node_s + node_e) / 2, node_e, query_s, query_e);
		t[idx].sum = get_size(idx * 2) + get_size(idx * 2 + 1);
	}
}

void remove(int y1, int y2)
{
	remove(1, 0, T, y1, y2);
}

long long get_answer()
{
	int xdi = 0;
	long long res = 0;

	for (int i = 0; i < q.size(); ++i)
	{
		query now = q[i];
		if (now.add == true)
			add(now.y1, now.y2);
		else
			remove(now.y1, now.y2);

		if (i == q.size() - 1 || q[i].x != q[i + 1].x)
			res += get_size(1) * xd[xdi++];
	}

	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		r[i].scan();

	x_compress();
	y_compress();
	make_query();
	initialize_tree();
	printf("%lld\n", get_answer());

	return 0;
}