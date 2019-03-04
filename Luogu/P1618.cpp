#include <stdio.h>
#include <string.h>

int main()
{
	char s[255];	
	int a,b,c,x,y,z,i,j,flag,ans=0;
	scanf("%d%d%d",&a,&b,&c);
	for(x=100;x<999;x++)
	{
		if(x%a!=0) continue;
		if(x/a*b>999||x/a*c>999) continue;
		flag=0;
		sprintf(s,"%d%d%d",x,x/a*b,x/a*c);
		for(i='1';i<='9';i++)
		{
			int k=0;
			for(j=0;j<9;j++)
				if(s[j]==i) k++;
			if(k!=1)
			{
				flag=1;
				break;
			}
		}
		if(flag) continue;
		ans++;
		printf("%d %d %d\n",x,x/a*b,x/a*c);
	}
	if(!ans) printf("No!!!");
	return 0;
}
