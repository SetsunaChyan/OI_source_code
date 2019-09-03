#include <bits/stdc++.h>
using namespace std;

char s[105];
int m[105],ans[105],pre[105];

bool cmp()
{
    int l1=0,l2=0;
    /*for(;m[100-l1]==0;l1++);
    for(;m[100-l1]!=0;l1++);
    for(;pre[100-l2]==0;l2++);
    if(l1>l2) return true;
    if(l1<l2) return false;*/
    for(int i=0;i<=100;i++)
    {
        if(m[i]>pre[i]) return true;
        if(m[i]<pre[i]) return false;
    }
    return true;
}

void mul()
{
    for(int i=0;i<=100;i++)
        pre[i]*=2;
    for(int i=100;i>0;i--)
        pre[i-1]+=pre[i]/10,pre[i]%=10;
}

void solve()
{
    scanf("%s",s);
    memset(m,0,sizeof(m));
    memset(ans,0,sizeof(ans));
    int l=strlen(s);
    for(int i=0;i<l;i++)
        m[101-l+i]=s[i]-'0';
    ans[100]=1;
    while(1)
    {
        for(int i=0;i<=100;i++)
            pre[i]=ans[i];
        mul();
        for(l=0;m[l]==0;l++);
        if(!cmp()) break;
        for(int i=0;i<=100;i++)
            ans[i]=pre[i];
    }
    for(l=0;ans[l]==0;l++);
    for(;l<=100;l++)
        printf("%d",ans[l]);
    printf("\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
