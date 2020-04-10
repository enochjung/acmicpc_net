#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct point
{
	int x, y;
} a[75010];

class segment_tree
{
private:
	const static int MAX_SIZE = 1<<18;
	int arr[MAX_SIZE];

	int get(int index, int from, int to, int left, int right)
	{
		if(to<=left || right<=from)
			return 0;
		if(from<=left && right<=to)
			return arr[index];

		int mid = (left+right)/2;
		return get(index*2, from, to, left, mid) + get(index*2+1, from, to, mid, right);
	}

public:
	segment_tree()
	{
		memset(arr, 0, sizeof(arr));
	}

	int get(int value)
	{
		return get(1, value, MAX_SIZE>>1, 0, MAX_SIZE>>1);
	}

	void add(int index)
	{
		for(index+=MAX_SIZE>>1; index>0; index>>=1)
			arr[index]++;
	}
};

int t, n;

bool compare_y(const point &i, const point &j)
{
	return i.y < j.y;
}

bool compare_xy(const point &i, const point &j)
{
	return i.x!=j.x? i.x<j.x : i.y>j.y;
}

void compress()
{
	sort(a, a+n, compare_y);

	int idx=0, before=a[0].y;
	a[0].y=0;

	for(int i=1; i<n; i++)
	{
		if(a[i].y == before)
			a[i].y = idx;
		else
		{
			before = a[i].y;
			a[i].y = ++idx;
		}
	}
}

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d %d", &a[i].x, &a[i].y);

		compress();
		sort(a, a+n, compare_xy);

		long long res = 0;
		segment_tree tree;
		for(int i=0; i<n; i++)
		{
			res += tree.get(a[i].y);
			tree.add(a[i].y);
		}

		printf("%lld\n", res);
	}
	return 0;
}
