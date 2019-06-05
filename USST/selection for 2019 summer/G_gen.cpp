#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];
int x1,x2,y1,y2,r,R;

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen()
{
	int t=100;
	printf("%d\n",t);
	for(int i=0;i<t;i++)
	{
		x1=rnd(-100,100);
		x2=rnd(-100,100);
		y1=rnd(-100,100);
		y2=rnd(-100,100);
		r=rnd(1,400);
		R=rnd(1,400);
		printf("%d %d %d %d %d %d\n",x1,y1,r,x2,y2,R);
	}
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=20;i++)
    {
		sprintf(des,"%d.in",i);
	    freopen(des,"w",stdout);
	    gen();
	   	fclose(stdout); 	
	}
    return 0;
}
