#include <bits/stdc++.h>
using namespace std;

int n,a[100005],b[100005],p[100005];

void gao(int flag,int l,int r)
{
    int mn=0x3f3f3f3f,mx=0;
    for(int i=l;i<=r;i++) mn=min(mn,a[i]),mx=max(mx,a[i]);
    for(int i=l;i<=r;i++) a[i]=flag==1?mn:mx;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) scanf("%d",b+i);
    int cur=1;
    for(int i=1;i<=n;i++)
    {
        while(cur<=n&&a[cur]!=b[i]) cur++;
        if(cur==n+1) return printf("-1"),0;
        p[i]=cur;
    }
    printf("%d\n",2*n);
    int mx=0;
    for(int i=1;i<p[1];i++) mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[p[i]]>=mx) printf("m %d %d\n",i,max(i,p[i]-1)),printf("M %d %d\n",min(i,p[i]),max(p[i],i));
        else printf("M %d %d\n",i,max(i,p[i]-1)),printf("m %d %d\n",min(i,p[i]),max(p[i],i));
        if(a[p[i]]>=mx) gao(1,i,max(i,p[i]-1)),gao(2,min(i,p[i]),max(p[i],i));
        else gao(2,i,max(i,p[i]-1)),gao(1,min(i,p[i]),max(p[i],i));
        mx=b[i];
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}

/*
5
1 2 3 4 4
2 2 2 2 5

5
1 5 5 3 4
1 1 4 4 4

5
5 1 1 3 4
5 5 4 4 4
*/
