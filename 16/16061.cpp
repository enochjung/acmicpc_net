#include <cstdio>
#include <algorithm>
#define N 10000

using namespace std;

struct employee
{
	char* name;
	int salary;
	bool operator<(const employee &hs) const
	{
		return salary > hs.salary;
	}
};

int n, d, k;
employee e[N];

int main()
{
	scanf("%d %d %d", &n, &d, &k);
	for (int i=0; i<n; ++i)
	{
		e[i].name = new char[10];
		scanf("%s %d", e[i].name, &e[i].salary);
	}
	
	sort(e, e+n);

	int idx = 0;
	for (int s=0; idx<k && s<d; ++idx)
	{
		s += e[idx].salary;
		if (s >= d)
			break;
	}

	if (idx == k)
		printf("impossible\n");
	else
	{
		printf("%d\n", idx+1);
		for (int i=0; i<=idx; ++i)
			printf("%s, YOU ARE FIRED!\n", e[i].name);
	}
	return 0;
}