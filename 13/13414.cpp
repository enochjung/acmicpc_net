#include <stdio.h>
#include <stack>
#include <map>

using namespace std;

int k, l;
int a[500010];
stack<int> res;
map<int, bool> check;

int main()
{
	scanf("%d %d", &k, &l);
	for(int i=0; i<l; i++)
		scanf("%d", a+i);

	for(int i=l-1; i>=0; i--)
		if(!check[a[i]]) {
			check[a[i]] = true;
			res.push(a[i]);
		}

	for(int i=0; i<k && !res.empty(); i++) {
		printf("%08d\n", res.top());
		res.pop();
	}
}
