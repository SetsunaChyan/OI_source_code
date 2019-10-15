#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

ll n,k,c[26][26],B[26];

void gao(int q,ll kth)
{
    //printf("GAO: %d %lld\n",q,kth);
    for(int i=0;i<q;i++)
        printf("%c",'A'+i);
    kth--;
    for(int i=n-q-1;i>=0;i--)
    {
        ll base=1;
        for(int j=1;j<=i;j++) base*=q;
        printf("%c",'A'+kth/base);
        kth%=base;
    }
}

void f(ll now,ll kth)
{
    if(now==1)
    {
        printf("A");
        return;
    }
    ll sum=0;
    for(int i=now-1;i>=0;i--)
    {
        sum+=c[now-1][i]*B[i];
        //printf("qaq %lld %d %lld %lld\n",now,i,c[now-1][i],B[i]);
        if(kth<=sum)
        {
            if(i==now-1) printf("A"),f(now-1,kth);
            else gao(now-i,kth-sum+c[now-1][i]*B[i]);
            break;
        }
    }
}

void solve(int cs)
{
    n=read();k=read();
    printf("Case #%d: ",cs);
    f(n,k);
    puts("");
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=26;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    memset(B,0,sizeof(B));
    B[0]=1;
    B[1]=1;
    for(int i=2;i<=5;i++)
    {
        for(int j=0;j<i;j++)
            B[i]+=B[j]*c[i-1][j];//,printf("B[%d]+=B[%d]*C[%d][%d] %lld %lld %lld\n",i,j,i-1,j,B[i],B[j],c[i-1][j]);
    }
    //printf("1111111111111 %lld %lld\n",B[1],B[2]);
    for(int i=1;i<=_;i++) solve(i);
    return 0;
}
