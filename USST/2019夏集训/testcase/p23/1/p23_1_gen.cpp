#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];
char s[200005];

int rnd(int l,int r)
{
    if(r<l) return 0;
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen(int r,int c,int q,int qaq)
{
    int sum=0;
    printf("%d %d %d\n",r,c,q);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int k=rnd(1,qaq);
            sum+=k;
            printf("%d ",k);
        }
        puts("");
    }
    sum/=r*c;
    for(int i=0;i<q;i++)
    {
        int x1=rnd(1,r),y1=rnd(1,c),x2=rnd(1,r),y2=rnd(1,c),k;
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        k=rnd(1,(x2-x1+1)*(y2-y1+1)*sum);
        if(k<=0) k=1;
        printf("%d %d %d %d %d\n",x1,y1,x2,y2,k);
    }
}

int main()
{
    srand(time(NULL));
    for(int i=1;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=5) gen(5,5,5,20);
        else if(i<=10) gen(10,10,10,20);
        else if(i<=15) gen(100,100,100,100);
        else if(i<=20) gen(200,200,200000,1000);
        fclose(stdout);
    }
    return 0;
}
