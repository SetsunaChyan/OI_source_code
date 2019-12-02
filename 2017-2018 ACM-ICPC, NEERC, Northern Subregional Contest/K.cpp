#include <bits/stdc++.h>
using namespace std;

int h,w;
vector<int>col;
vector<int>row;

int n;

void PRINT(int a,int b)
{
	int flag=1;
	for(int i=0;i<h;i++)
	{
		flag=0;
		if(i%2&&a)
		{
			flag=1;
			a--;
		}
		for(int j=0;j<w;j++)
		{
			if(flag||(j%2&&j<b*2))
			{
				printf("#");
			}
			else
			{
				printf(".");
			}

		}
		printf("\n");
	}
}

int main()
{

	freopen("kotlin.in","r",stdin);
	freopen("kotlin.out","w",stdout);

	scanf("%d %d %d",&h,&w,&n);
	for(int i=1;i<=(h+1)/2;i++)
	{
		row.push_back(i);
	}
	for(int i=1;i<=(w+1)/2;i++)
	{
		col.push_back(i);
	}
	int flag=1;
	for(int i=0;i<row.size()&&flag;i++)
	{
		for(int j=0;j<col.size()&&flag;j++)
		{
			if(row[i]*col[j]==n)
			{
				PRINT(row[i]-1,col[j]-1);
				flag=0;
				break;
			}
		}
	}
	if(flag)
	{
		printf("Impossible");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
