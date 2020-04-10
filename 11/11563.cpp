#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct road
{
	double xs, ys, xe, ye;
};

int n, m;
road a[2010], b[2010];

double inner(double x1, double y1, double x2, double y2) { return x1*x2 + y1*y2; }
double outer(double x1, double y1, double x2, double y2) { return x1*y2 - x2*y1; }
double distance(double x1, double y1, double x2, double y2) { return sqrt(pow(x1-x2,2) + pow(y1-y2,2)); }

bool perpendicular(double px, double py, double x1, double y1, double x2, double y2)
{
	return inner(px-x1,py-y1,x2-x1,y2-y1) * inner(px-x2,py-y2,x1-x2,y1-y2) >= 0;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%lf %lf %lf %lf", &a[i].xs, &a[i].ys, &a[i].xe, &a[i].ye);
	for(int i=0; i<m; i++)
		scanf("%lf %lf %lf %lf", &b[i].xs, &b[i].ys, &b[i].xe, &b[i].ye);

	double res = 999999;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			double axs=a[i].xs, ays=a[i].ys, axe=a[i].xe, aye=a[i].ye;
			double bxs=b[j].xs, bys=b[j].ys, bxe=b[j].xe, bye=b[j].ye;

			res = min(res, distance(axs,ays, bxs,bys));
			res = min(res, distance(axe,aye, bxs,bys));
			res = min(res, distance(axs,ays, bxe,bye));
			res = min(res, distance(axe,aye, bxe,bye));

			if(perpendicular(axs,ays,bxs,bys,bxe,bye)) res = min(res, fabs(outer(bxs-axs,bys-ays, bxe-bxs,bye-bys))/distance(bxs,bys,bxe,bye));
			if(perpendicular(axe,aye,bxs,bys,bxe,bye)) res = min(res, fabs(outer(bxs-axe,bys-aye, bxe-bxs,bye-bys))/distance(bxs,bys,bxe,bye));
			if(perpendicular(bxs,bys,axs,ays,axe,aye)) res = min(res, fabs(outer(axs-bxs,ays-bys, axe-axs,aye-ays))/distance(axs,ays,axe,aye));
			if(perpendicular(bxe,bye,axs,ays,axe,aye)) res = min(res, fabs(outer(axs-bxe,ays-bye, axe-axs,aye-ays))/distance(axs,ays,axe,aye));
		}

	printf("%.9lf\n", res);
	return 0;
}
