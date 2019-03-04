#include <stdio.h>
#include <math.h>

int base[1000],r[1000];

void multi(int *a,int *b)
{
	int i=999,j=999,c[1000];
	for(i=0;i<1000;i++) c[i]=0;
	for(i=999;i>=500;i--)
		for(j=999;j>=500;j--)
			c[i+j-999]+=a[i]*b[j];
	for(i=999;i>=500;i--)
	{
		c[i-1]+=c[i]/10;
		a[i]=c[i]%10;
	}
}

int main()
{
	int p,i,j;
	scanf("%d",&p);
	printf("%d",(int)(p*log(2)/log(10))+1);
	
	for(i=0;i<1000;i++) 
	{
		r[i]=0;
		base[i]=0;
	}
	base[999]=2;
	r[999]=1;
	
	while(p)
	{
		if(p&1) multi(r,base);
		multi(base,base);
		p>>=1; 
	}
	r[999]-=1;
	for(i=500;i<1000;i++)
	{
		if(i%50==0) printf("\n");
		printf("%d",r[i]); 
	}
	return 0;
}
