#include <cstdio>
#define SIZE 1000010

int n;
int t[SIZE];

int get(int pos)
{
	int sum = 0;
	while(pos)
	{
		sum += t[pos];
		pos -= pos&-pos;
	}
	return sum;
}

void update(int pos, int val)
{
	while(pos < SIZE)
	{
		t[pos] += val;
		pos += pos&-pos;
	}
}

int find(int rank)
{
	int res = 0;
	int low=1, high=1000000;

	while(low <= high)
	{
		int mid = (low+high)/2;

		if(get(mid) >= rank)
		{
			res = mid;
			high = mid-1;
		}
		else
			low = mid+1;
	}

	return res;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int a, b, c;
		scanf("%d", &a);
		if(a == 1)
		{
			scanf("%d", &b);
			int val = find(b);
			printf("%d\n", val);
			update(val, -1);
		}
		else
		{
			scanf("%d %d", &b, &c);
			update(b, c);
		}
	}
	
	return 0;
}
