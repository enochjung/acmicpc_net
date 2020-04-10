#include <stdio.h>
#include <algorithm>
#include <stack>

#define N 1000010

using namespace std;

int n, a[N];
int s, d[N], p[N], r[N];
stack<int> res;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", a+i);

		int idx = (int)(lower_bound(d, d+s, a[i]) - d);
		d[idx] = a[i];
		p[idx] = i;
		r[i] = (idx>0? p[idx-1] : -1);
		if(idx == s) s++;
	}
	
	int idx = p[s-1];
	do {
		res.push(a[idx]);
		idx = r[idx];
	} while(idx != -1);

	printf("%d\n", s);
	while(!res.empty()) {
		printf("%d ", res.top());
		res.pop();
	}
}
