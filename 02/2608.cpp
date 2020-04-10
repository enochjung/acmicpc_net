#include <cstdio>
#include <stack>

using namespace std;

const char s[10] = "IVXLCDM";
const int v[10] = {1,5,10,50,100,500,1000};
char a[20], b[20];
int res;
stack<char> roma;

void sum(char t[])
{
	for(int i=0; t[i]; i++)
	{
		bool flag = false;
		for(int j=0; j<3; j++)
		{
			if(t[i]==s[j*2] && t[i+1]==s[j*2+1])
			{
				res += v[j*2+1]-v[j*2];
				i++;
				flag = true;
			}
			else if(t[i]==s[j*2] && t[i+1]==s[j*2+2])
			{
				res += v[j*2+2]-v[j*2];
				i++;
				flag = true;
			}
		}
		if(!flag)
			for(int j=0; j<7; j++)
				if(t[i] == s[j])
				{
					res += v[j];
					break;
				}
	}
}

void make()
{
	for(int i=0; res>0; i++,res/=10)
	{
		int num = res%10;

		if(num == 4)
		{
			roma.push(s[i*2+1]);
			roma.push(s[i*2]);
		}
		else if(num == 9)
		{
			roma.push(s[i*2+2]);
			roma.push(s[i*2]);
		}
		else
		{
			for(int j=0; j<num%5; j++)
				roma.push(s[i*2]);
			if(num>=5)
			roma.push(s[i*2+1]);
		}
	}
}

int main()
{
	scanf("%s %s", a, b);

	sum(a);
	sum(b);
	printf("%d\n", res);
	make();
	while(!roma.empty())
	{
		printf("%c", roma.top());
		roma.pop();
	}

	return 0;
}
