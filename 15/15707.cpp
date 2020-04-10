#include <cstdio>
#include <cstring>

char sa[30], ca[30], sb[30], cb[30];
long long a, b, r;

int main()
{
	scanf("%s %s %lld", sa, sb, &r);

	char buf[60];
	sprintf(buf, "%s %s", sa, sb);
	sscanf(buf, "%lld %lld", &a, &b);
	sprintf(ca, "%lld", a);
	sprintf(cb, "%lld", b);

	if(a==0 || b==0)
		printf("0");
	else if(strcmp(sa, ca) || strcmp(sb, cb) || a>r/b)
		printf("overflow");
	else
		printf("%lld", a*b);
	return 0;
}
