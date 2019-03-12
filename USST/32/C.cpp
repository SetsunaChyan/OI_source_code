#include <cstdio>

int main()
{
	double a,b,A,B,t1,t2;
	scanf("%lf%lf",&a,&b);
	a/=100,b/=100;
	A=a,B=b*(1-a);
	t1=(1-a);
	t2=(1-b);
	for(int i=0;i<10000;i++)
	{
		A+=a*t1*t2;
		t1*=(1-a);
		t2*=(1-b);
	}
	t1=(1-a)*(1-a);
	t2=(1-b);
	for(int i=0;i<10000;i++)
	{
		B+=b*t1*t2;
		t1*=(1-a);
		t2*=(1-b);
	}
	if(A>B) printf("Ben");
	else if(A<B) printf("Oak");
	else printf("equal");
	return 0;
}