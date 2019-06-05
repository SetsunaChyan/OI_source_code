#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];
int n,m,l,r,x,k,a[100005];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void shuf(int n,int k)
{
	for(int i=1;i<=n;i++)
		a[i]=i;
	while(k--)
	{
		int l=rnd(1,n),r=rnd(1,n);
		int tmp=a[l];
		a[l]=a[r];
		a[r]=tmp;
	}
}

void gen0()
{
	printf("100000 1\n1 1 1 1");
}

void gen1()
{
	n=100000,m=rnd(1,100000);
	printf("%d %d\n",n,m);
	shuf(n,n<<1);
	for(int i=0;i<m;i++)
	{
		l=rnd(1,n);r=rnd(l,n);k=rnd(1,r-l+1);
		printf("%d %d %d %d\n",l,r,k,a[l+k-1]);
	}
}

void gen2()
{
	n=100000,m=rnd(1,100000);
	printf("%d %d\n",n,m);
	for(int i=0;i<m;i++)
	{
		l=rnd(1,n);r=rnd(l,n);k=rnd(1,r-l+1);x=rnd(1,n);
		printf("%d %d %d %d\n",l,r,k,x);
	}
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=2;i++)
    {
		sprintf(des,"%d.in",i);
	    freopen(des,"w",stdout);
	    gen0();
	   	fclose(stdout); 	
	}
    for(int i=3;i<=10;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen1();
        fclose(stdout);
    }
    for(int i=11;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen2();
        fclose(stdout);
    }
    return 0;
}
