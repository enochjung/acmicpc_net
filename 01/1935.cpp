#include <cstdio>
#include <stack>

using namespace std;

int n, a[30];
char s[110];
stack<double> t;

double pop()
{
	double tmp = t.top();
	t.pop();
	return tmp;
}

int main()
{
	scanf("%d %s", &n, s);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	for(int i=0; s[i]; ++i)
	{
		double p, q;
		switch(s[i])
		{
		case '+':
			q = pop();
			p = pop();
			t.push(p+q);
			break;
		case '-':
			q = pop();
			p = pop();
			t.push(p-q);
			break;
		case '*':
			q = pop();
			p = pop();
			t.push(p*q);
			break;
		case '/':
			q = pop();
			p = pop();
			t.push(p/q);
			break;
		default:
			t.push(a[s[i]-'A']);
		}
	}

	printf("%.2lf", t.top());
	return 0;
}
