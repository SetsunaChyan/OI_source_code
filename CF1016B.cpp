#include <bits/stdc++.h>
using namespace std;

int n,m,pre[2005],q;
char s[2005],t[2005];

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s%s",s,t);
    for(int i=0;i<n-m+1;i++)
    {
        int flag=1;
        for(int j=0;j<m;j++)
            if(s[i+j]!=t[j])
            {
                flag=0;
                break;
            }
        if(flag) pre[i+1]++;
    }
    for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",pre[max(r-m+1,l-1)]-pre[l-1]);
    }
    return 0;
}
