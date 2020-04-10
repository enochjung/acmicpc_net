#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#define N 10010

using namespace std;

int n, m;
int d[N*2], si[N*2], sn;
bool finish[N*2];
stack<int> s;
vector<int> e[N*2];
 
int neg(int x)
{
	return x&1? x-1 : x+1;
}
 
int f(int x)
{
	static int cnt = 0;
	d[x] = ++cnt;
	s.push(x);

	int top = d[x];
	for(int to : e[x])
	{
		if(d[to] == 0)
			top = min(top, f(to));
		else if(!finish[to])
			top = min(top, d[to]);
	}

	if(top == d[x])
	{
		int v = -1;
		while(v != x)
		{
			v = s.top();
			s.pop();
			finish[v] = true;
			si[v] = sn;
		}
		++sn;
	}

	return top;
}
 
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i) 
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a = (a>0? a*2-2 : -a*2-1);
		b = (b>0? b*2-2 : -b*2-1);
		e[neg(a)].push_back(b);
		e[neg(b)].push_back(a);
	}
 
	for(int i=0; i<n*2; ++i)
		if(d[i] == 0)
			f(i);

	for(int i=0; i<n; ++i)
		if(si[i*2] == si[i*2+1])
		{
			puts("0");
			return 0;
		}
	printf("1\n");
	for(int i=0; i<n; ++i)
		printf("%d ", si[i*2]<si[i*2+1]);
	return 0;
}
