#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int a[310];
bool cut[310];

int f(int x)
{
	int cnt=1, sum=0;

	for(int i=0; i<n; i++)
	{
		if(sum+a[i] > x)
		{
			sum = 0;
			cnt++;
		}
		sum += a[i];
	}

	return cnt;
}

int main()
{
	int left=0, right=0;

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
	{
		scanf("%d", a+i);
		left = max(left, a[i]);
		right += a[i];
	}

	while(left <= right)
	{
		int mid = (left+right)/2;
		if(f(mid) <= m)
			right = mid-1;
		else
			left = mid+1;
	}
	
	int sum=0, prt=0;
	for(int i=0; i<n; i++)
	{
		sum += a[i];
		if(i==n-1 || sum+a[i+1]>left)
		{
			cut[i] = true;
			sum = 0;
			prt++;
		}
	}

	int def = m-prt;
	int cnt = 0;

	printf("%d\n", left);
	for(int i=0; i<n; i++)
	{
		cnt++;
		if(cut[i])
		{
			printf("%d ", cnt);
			cnt = 0;
		}
		else if(def)
		{
			printf("%d ", cnt);
			cnt = 0;
			def--;
		}
	}

	return 0;
}
