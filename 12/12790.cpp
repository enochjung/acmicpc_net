#include <cstdio>
#include <algorithm>

using namespace std;

int t;
int hp, mp, atk, def;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &hp, &mp, &atk, &def);
		scanf("%d %d %d %d", &a, &b, &c, &d);

		hp = max(hp+a, 1);
		mp = max(mp+b, 1);
		atk = max(atk+c, 0);
		def += d;

		printf("%d\n", hp+5*mp+2*atk+2*def);
	}
	return 0;
}
