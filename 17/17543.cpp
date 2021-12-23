#include <cstdio>
#include <cstdlib>
#include <stack>
#define N 300010
#define LP -1
#define RP -2
#define MOD 1000000007

using namespace std;

int n, a[N];
int pi[N];

void set_pi()
{
	stack<int> s;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == LP)
			s.push(i);
		else if (a[i] == RP)
		{
			int idx = s.top();
			pi[idx] = i;
			s.pop();
		}
	}
}

int f(int s, int e, bool add)
{
	int res = add ? 0 : 1;

	for (int i = s; i < e; ++i)
	{
		if (a[i] == LP)
		{
			if (add)
				res = (res + f(i + 1, pi[i], !add)) % MOD;
			else
				res = (1LL * res * f(i + 1, pi[i], !add)) % MOD;

			i = pi[i];
		}
		else
		{
			if (add)
				res = (res + a[i]) % MOD;
			else
				res = (1LL * res * a[i]) % MOD;
		}
	}

	return res;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		char c[20];
		scanf(" %s", c);

		if (c[0] == '(')
			a[i] = LP;
		else if (c[0] == ')')
			a[i] = RP;
		else
			a[i] = atoi(c);
	}

	set_pi();
	printf("%d\n", f(0, n, true));

	return 0;
}