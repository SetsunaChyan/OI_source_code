#include <bits/stdc++.h>
using namespace std;

int n,k,tmp[100005],a[100005];

void merge_shuffle(int l,int r)
{
    if(!k) return;
    if(l+1==r) return;
    int m=l+r>>1;
    for(int i=l;i<m;i++) tmp[i]=a[i];
    for(int i=l;i<m;i++) a[i]=a[i-l+m];
    if(m-l!=r-m)
        for(int i=m;i<r-1;i++) a[i]=tmp[i-m+l];
    else
        for(int i=m;i<r;i++) a[i]=tmp[i-m+l];
    k-=2;
    merge_shuffle(l,m);
    merge_shuffle(m,r);
}

int main()
{
    scanf("%d%d",&n,&k);
    if(k%2==0||k>2*n-1) return printf("-1"),0;
    for(int i=0;i<n;i++) a[i]=i+1;
    k--;
    merge_shuffle(0,n);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
