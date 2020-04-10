#include <stdio.h>
#include <algorithm>

using namespace std;

struct st { 
	int s, e;
	bool operator<(const st &i) const { return e==i.e? s<i.s : e<i.e; }
} t[100010];

int n;
int et, cnt;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", &t[i].s, &t[i].e);

	sort(t, t+n);

	for(int i=0; i<n; i++)
		if(et <= t[i].s) {
			et = t[i].e;
			cnt++;
		}

	printf("%d", cnt);
}
