#include <cstdio>
#include <cstring>

const int pp[10]={1,0,0,0,1,0,1,0,2,1};
int t,y;
char x[105];

inline int min(int a,int b){return a<b?a:b;}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%s %d",x,&y);
		if(y==0)
		{
			printf("%s\n",x);
			continue;
		}
		int l=strlen(x),k=0;
		for(int i=0;i<l;i++)
			k+=pp[x[i]-'0'];
		for(int i=1;i<min(y,5);i++)
		{
			int e=0;
			if(k==0)
			{
				k=1;
				continue;
			}
			while(k)
			{
				e+=pp[k%10];
				k/=10;
			}
			k=e;
		}
		if(y<=5)
			printf("%d\n",k);
		else
			printf("%d\n",k==1?k-(y-5)%2:(y-5)%2);
	}
	return 0;
}