#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int d[2][5][5];

int move(int a, int b)
{
	if (a == b)
		return 1;
	if (a == 0)
		return 2;
	if (abs(a-b) != 2)
		return 3;
	return 4;
}

void update(int a, int i, int j, int p, int q)
{
	int &target = p>0? d[a][p][j] : d[a][i][q];
	int source = d[1-a][i][j];
	int cost = p>0? move(i,p) : move(j,q);

	if (target==-1 || target>source+cost)
		target = source+cost;
}

int main()
{
	memset(d, -1, sizeof(int)*25);
	d[0][0][0] = 0;
	for (int b=0;; b=1-b)
	{
		int v;
		scanf("%d", &v);
		if (v == 0)
		{
			int res = -1;
			for (int i=0; i<5; ++i)
				for (int j=0; j<5; ++j)
					if (d[b][i][j] != -1)
						if (res==-1 || res>d[b][i][j])
							res = d[b][i][j];
			printf("%d\n", res);
			break;
		}

		int a = 1-b;
		memset(&d[a], -1, sizeof(int)*25);
		for (int i=0; i<5; ++i)
			for (int j=0; j<5; ++j)
				if (d[b][i][j] != -1)
				{
					update(a, i, j, 0, v);
					update(a, i, j, v, 0);
				}
	}
	return 0;
}