#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=8005;
ll tmp[MAXN],dif[MAXN],a[MAXN],b[MAXN],org[MAXN],tmp2[MAXN];
int n,q;

void solve(int cs)
{
    int tot=0;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
    {
        scanf("%d%d",a+i,b+i),tmp[tot++]=a[i],tmp[tot++]=b[i],tmp[tot++]=a[i]+1,tmp[tot++]=b[i]+1;
        //if(b[i]!=n) tmp[tot++]=b[i]+1;
    }
    tmp[tot++]=n;
    sort(tmp,tmp+tot);
    tot=unique(tmp,tmp+tot)-tmp;
    for(int i=0;i<tot;i++)
        org[i+1]=tmp[i];
    for(int i=1;i<=q;i++)
    {
        int k=lower_bound(tmp,tmp+tot,a[i])-tmp+1;
        //org[k]=a[i];
        a[i]=k;
        k=lower_bound(tmp,tmp+tot,b[i])-tmp+1;
        //org[k]=b[i];
        b[i]=k;
    }
	for(int i=1;i<=tot;i++) dif[i]=0;
	for(int i=1;i<=q;i++)
		dif[a[i]]++,dif[b[i]+1]--;
    for(int i=1;i<=tot;i++)
        dif[i]+=dif[i-1];
    ll ans=0;
    /*for(int i=1;i<=tot;i++)
        printf("%lld ",org[i]);
    puts("");
    for(int i=1;i<=tot;i++)
        printf("%d ",dif[i]);
    puts("");*/
    for(int i=1;i<tot;i++)
        if(dif[i]&1) ans+=org[i+1]-org[i];
    printf("Case #%d: %lld\n",cs,ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=_;i++) solve(i);
    return 0;
}

/*
1000
1000000 2
1 1000000
2 999999
*/
