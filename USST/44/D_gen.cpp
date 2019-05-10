#include <bits/stdc++.h>
using namespace std;

int n,op,x1,x2,y1,y2;
char des[100];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen1()
{
    n=10;
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        int k=rand()%5;
        if(k<=1) op=1; else op=k;
        if(op==1)
        {
            x1=rnd(1,10);
            y1=rnd(1,10);
            x2=rnd(1,10);
            y2=rnd(1,10);
            while(x1==x2&&y1==y2) x2=rnd(1,10),y2=rnd(1,10);
            printf("%d %d %d %d %d\n",op,x1,y1,x2,y2);
        }
        else if(op==4)
        {
            printf("%d\n",op);
        }
        else
        {
            int q=rnd(1,10);
            printf("%d %d\n",op,q);
        }
    }
}

void gen2()
{
    n=1000;
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        int k=rand()%5;
        if(k<=1) op=1; else op=k;
        if(op==1)
        {
            x1=rnd(1,1000);
            y1=rnd(1,1000);
            x2=rnd(1,1000);
            y2=rnd(1,1000);
            while(x1==x2&&y1==y2) x2=rnd(1,1000),y2=rnd(1,1000);
            printf("%d %d %d %d %d\n",op,x1,y1,x2,y2);
        }
        else if(op==4)
        {
            printf("%d\n",op);
        }
        else
        {
            int q=rnd(1,1000);
            printf("%d %d\n",op,q);
        }
    }
}

void gen3()
{
    n=10000;
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        int k=rand()%5;
        if(k<=1) op=1; else op=k;
        if(op==1)
        {
            x1=rnd(1,100000);
            y1=rnd(1,100000);
            x2=rnd(1,100000);
            y2=rnd(1,100000);
            while(x1==x2&&y1==y2) x2=rnd(1,100000),y2=rnd(1,100000);
            printf("%d %d %d %d %d\n",op,x1,y1,x2,y2);
        }
        else if(op==4)
        {
            printf("%d\n",op);
        }
        else
        {
            int q=rnd(1,100000);
            printf("%d %d\n",op,q);
        }
    }
}

void gen4()
{
    n=100000;
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        int k=rand()%5;
        if(k<=1) op=1; else op=k;
        if(op==1)
        {
            x1=rnd(1,100000);
            y1=rnd(1,100000);
            x2=rnd(1,100000);
            y2=rnd(1,100000);
            while(x1==x2&&y1==y2) x2=rnd(1,100000),y2=rnd(1,100000);
            printf("%d %d %d %d %d\n",op,x1,y1,x2,y2);
        }
        else if(op==4)
        {
            printf("%d\n",op);
        }
        else
        {
            int q=rnd(1,100000);
            printf("%d %d\n",op,q);
        }
    }
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=40;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen1();
        else if(i<=20) gen2();
        else if(i<=30) gen3();
        else gen4();
        fclose(stdout);
    }
    return 0;
}