#include <stdio.h>

int x[10], y[10];

int outer(int x1, int y1, int x2, int y2)
{
	return x1*y2 - x2*y1;
}

int main()
{
	for(int i=0; i<3; i++)
		scanf("%d %d", x+i, y+i);

	int res = outer(x[1]-x[0], y[1]-y[0], x[2]-x[1], y[2]-y[1]);

	printf("%d\n", res>0? 1 : (res<0? -1 : 0));
	return 0;
}
