#include <cstdio>
#include <cstdlib>

int x[36], y[36];
bool visited[6][6];

bool knight(int i, int j)
{
	return abs(x[i]-x[j])*abs(y[i]-y[j]) == 2;
}

bool f()
{
	for(int i=0; i<36; ++i)
	{
		if(visited[x[i]][y[i]])
			return false;
		visited[x[i]][y[i]] = true;
		if(!knight(i, (i+1)%36))
			return false;
	}

	return true;
}

int main()
{
	for(int i=0; i<36; ++i)
	{
		char a, b;
		scanf(" %c%c", &a, &b);
		x[i] = a-'A';
		y[i] = b-'1';
	}
	printf("%s", f()? "Valid" : "Invalid");
	return 0;
}
