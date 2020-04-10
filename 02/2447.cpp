#include <cstdio>
#include <cmath>

int n, k;
bool a[6570][6570];

int main()
{
    int m;
    
    scanf("%d", &n);
    
	for(m=0; n>1; m++)
		n /= 3;
    n = pow(3, m);
    
	for(int t=0; t<m; t++)
		for(int i=pow(3,t); i<n; i+=pow(3,t+1))
			for(int j=pow(3,t); j<n; j+=pow(3,t+1))
				for(int p=0; p<pow(3,t); p++)
					for(int q=0; q<pow(3,t); q++)
						a[i+p][j+q]=true;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%c", a[i][j]? ' ' : '*');
		printf("\n");
	}
    return 0;
}
