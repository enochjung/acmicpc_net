#include <cstdio>

#define N 100000

bool is_arithmetic_progression(int n, int a[]) {
	if (n < 3)
		return true;

	int diff = a[1] - a[0];
	for (int i=2; i<n; ++i)
		if (a[i]-a[i-1] != diff)
			return false;
	return true;
}

int main() {
	int n, a[N];

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);
	
	if (is_arithmetic_progression(n, a)) {
		printf("YES\n");
		for (int i=0; i<n; ++i)
			printf("%d ", a[i]);
		printf("\n");
		for (int i=0; i<n; ++i)
			printf("0 ");
		printf("\n");
	}
	else
		printf("NO\n");

    return 0;
}