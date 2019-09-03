#include <bits/stdc++.h>
using namespace std;

int n,m;
char des[100];
char s[200005];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen_hack_bf()
{
    for(int i=0;i<200;i++)
    {
        for(int j=0;j<999;j++)
            printf("q");
        if(i==100) printf("a"); else printf("q");
    }
    printf("\n");
    for(int i=0;i<999;i++)
        printf("q");
    printf("a");
}

void gen(int n)
{
    int l=rnd(0,n-1),r=rnd(0,n-1),k=rnd(1,26);
    if(r<l) swap(l,r);
    for(int i=0;i<n;i++)
        s[i]=rand()%k+'a';
    s[n]=0;
    printf("%s\n",s);
    for(int i=l;i<=r;i++)
        printf("%c",s[i]);
}

void gen2(int n)
{
    int p=rnd(1,min(n/2,100));
    for(int i=0;i<n;i++)
        s[i]=rand()%26+'a';
    s[n]=0;
    printf("%s\n",s);
    for(int i=0;i<n;i++)
        if(rand()%p==0) printf("%c",s[i]);
}

int main()
{
    srand(time(NULL));
    for(int i=5;i<=40;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i==5) gen_hack_bf();
        else if(i<=10) gen(10);
        else if(i<=15) gen(100);
        else if(i<=20) gen(200000);
        else if(i<=25) gen2(10);
        else if(i<=30) gen2(100);
        else if(i<=40) gen2(200000);
        fclose(stdout);
    }
    return 0;
}
