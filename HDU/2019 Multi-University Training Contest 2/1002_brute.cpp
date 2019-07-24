#include <bits/stdc++.h>
using namespace std;

int n,a[100],mintot=0,maxtot=0,maxa[100],mina[100],tmp[100];

void update1(int tot,int x[100])
{
    if(tot>mintot)
    {
        for(int i=0;i<tot;i++) mina[i]=x[i];
        mintot=tot;
        return;
    }
    for(int i=0;i<tot;i++) if(mina[i]<x[i]) return;
    for(int i=0;i<tot;i++) mina[i]=x[i];
}

void update2(int tot,int x[100])
{
    if(tot>maxtot)
    {
        for(int i=0;i<tot;i++) maxa[i]=x[i];
        maxtot=tot;
        return;
    }
    for(int i=0;i<tot;i++) if(maxa[i]>x[i]) return;
    for(int i=0;i<tot;i++) maxa[i]=x[i];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=1;i<(1<<n);i++)
    {
        int tot=0,t=i,k;
        for(int j=0;j<n;j++)
        {
            if(t&1) tmp[tot++]=j;
            t>>=1;
        }
        for(k=0;k<tot-1;k++) if(a[tmp[k+1]]<=a[tmp[k]]) break;
        if(k!=tot-1&&a[tmp[k+1]]==a[tmp[k]]) continue;
        for(;k<tot-1;k++) if(a[tmp[k+1]]>=a[tmp[k]]) break;
        if(k!=tot-1) continue;
        if(tot>=mintot) update1(tot,tmp);
        if(tot>=maxtot) update2(tot,tmp);
    }
    for(int i=0;i<mintot;i++)
        printf("%d ",mina[i]+1);
    puts("");
    for(int i=0;i<maxtot;i++)
        printf("%d ",maxa[i]+1);
    return 0;
}
