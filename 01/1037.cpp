#include <stdio.h>
#include <algorithm>

using namespace std;

int n, v;
int a=9999999, b=0;

int main()
{
	scanf("%d", &n);
    for(int i=0; i<n; i++) {
		scanf("%d", &v);
        a = min(a,v);
        b = max(b,v);
    }
    
	printf("%d", a*b);
}
