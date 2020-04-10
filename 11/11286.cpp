#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int n;

int abs(int x)
{
	return x>0? x : -x;
}

template<typename T>
struct myop {
	bool operator()(T a, T b) const
	{
		return abs(a)!=abs(b)? abs(a)>abs(b) : a>b;
	}
};

priority_queue<int,vector<int>,myop<int>> q;

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int v;
		scanf("%d", &v);
		
		if(v)
			q.push(v);
		else
		{
			if(q.empty())
				printf("0\n");
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
		}
	}

	return 0;
}
