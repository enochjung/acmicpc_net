#include <cstdio>

int n;
int disk_size;
int disk_state[3][21];

void f(int s, int from, int to)
{
	int another = 6-from-to;

	if(s == 1)
		printf("%d %d\n", from, to);
	else
	{
		f(s-1, from, another);
		f(1, from, to);
		f(s-1, another, to);
	}
}

int main(void)
{
	scanf("%d", &n);

	printf("%d\n", (1<<n)-1);
	f(n, 1, 3);
    return 0;
}
