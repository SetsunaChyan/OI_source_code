#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[5005];
const ll mod=998244353;
int a[5005],n,hsa[5005][5005];
short k[5005][5005];

int main()
{

    scanf("%s",s);
    n=strlen(s);
    for(int l=0;l<n;l++)
    {
        ll tmp=0;
        for(int r=l;r<n;r++)
            tmp=(tmp*26+s[r]-'a')%mod,hsa[l][r]=tmp;
    }
    for(int l=n-1;l>=0;l--)
    {
        ll tmp=0;
        for(int r=l;r>=0;r--)
            tmp=(tmp*26+s[r]-'a')%mod,hsa[l][r]=tmp;
    }
    for(int len=1;len<=n;len++)
        for(int i=0;i+len-1<n;i++)
        {
            if(len==1)
            {
                k[i][i]=1;
                continue;
            }
            int l=(i+len/2-1),r=i+len-len/2;
            if(hsa[i][l]==hsa[i+len-1][r]) k[i][i+len-1]=k[i][l]+1;
        }
    for(int l=0;l<n;l++)
        for(int r=l;r<n;r++)
            a[k[l][r]]++;
    for(int i=n;i;i--) a[i]+=a[i+1];
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
