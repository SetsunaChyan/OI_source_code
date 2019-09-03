#include <bits/stdc++.h>
using namespace std;

int n,m,a[400005];
char des[100];
char s[200005];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen_hack_bf()
{
    printf("1\n");
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

void gen_hack_kmp()
{
    int n=200000;
    printf("%d\n",n);
    for(int i=0;i<n;i++)
        s[i]=rand()%26+'a';
    s[n]=0;
    printf("%s\n",s);
    for(int i=n-1;i>=0;i--)
        printf("%c\n",s[i]);
}

void gen(int n,int q)
{
    printf("%d\n",q);
    int k=rnd(1,26);
    for(int i=0;i<2*n;i++)
        a[i]=rnd(0,n-1);
    sort(a,a+2*n);
    for(int i=0;i<n;i++)
        s[i]=rand()%k+'a';
    s[n]=0;
    printf("%s\n",s);
    for(int i=0;i<q;i++)
    {
        for(int j=a[i*2];j<=a[i*2+1];j++)
            printf("%c",s[j]);
        puts("");
    }
}

void gen2(int n,int q)
{
    printf("%d\n",q);
    int k=rnd(1,26),l=n/q;
    for(int i=0;i<n;i++)
        s[i]=rand()%k+'a';
    s[n]=0;
    printf("%s\n",s);
    for(int i=0;i<q;i++)
    {
        for(int j=i;j<i+l;j++)
            printf("%c",s[j]);
        puts("");
    }
}

int main()
{
    srand(time(NULL));
    for(int i=5;i<=30;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i==5) gen_hack_bf();
        else if(i<=10) gen_hack_kmp();
        else if(i<=15) gen(10,i);
        else if(i<=20) gen(100,i);
        else if(i<=25) gen(200000,100*(i-19));
        else if(i<=30) gen2(200000,100*(i-24));
        fclose(stdout);
    }
    return 0;
}
