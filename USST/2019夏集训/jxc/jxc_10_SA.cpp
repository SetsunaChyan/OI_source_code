#include <bits/stdc++.h>
using namespace std;

const int maxn=105;
int wa[maxn],wb[maxn],scnt[maxn],wcnt[maxn],sa[maxn],ss[maxn],rk[maxn],height[maxn];
char s[maxn];

inline bool cmp(int r[],int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}

void da(int r[],int sa[],int n,int m)
{
    int *t,*x=wa,*y=wb;
    for(int i=0;i<m;i++) wcnt[i]=0;
    for(int i=0;i<n;i++) wcnt[x[i]=r[i]]++;
    for(int i=1;i<m;i++) wcnt[i]+=wcnt[i-1];
    for(int i=n-1;i>=0;i--) sa[--wcnt[x[i]]]=i;
    for(int j=1,p=1;p<n;j*=2,m=p)
    {
        p=0;
        for(int i=n-j;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(int i=0;i<n;i++) scnt[i]=x[y[i]];
        for(int i=0;i<m;i++) wcnt[i]=0;
        for(int i=0;i<n;i++) wcnt[scnt[i]]++;
        for(int i=1;i<m;i++) wcnt[i]+=wcnt[i-1];
        for(int i=n-1;i>=0;i--) sa[--wcnt[scnt[i]]]=y[i];
        t=x,x=y,y=t,p=1,x[sa[0]]=0;
        for(int i=1;i<n;i++) x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(int i=0;i<n;i++) rk[sa[i]]=i;
    for(int i=0;i<n;i++)
        if(rk[i])
        {
            int pre=sa[rk[i]-1],l=max(height[rk[i-1]]-1,0);
            while(r[i+l]==r[pre+l]) l++;
            height[rk[i]]=l;
        }
}

int main()
{
    scanf("%s",s);
    int l=strlen(s);
    for(int i=0;i<l;i++)
        ss[i]=s[i]-'0';
    //ss[l++]=0;
    da(ss,sa,l,3);
    for(int i=0;i<l;i++)
        printf("%d ",height[i]);
    return 0;
}
