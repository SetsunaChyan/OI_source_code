#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,s,sum;
char ans[1000005];

void solve()
{
    sum=0;
    scanf("%d%d",&n,&s);
    if(s==1&&n==1)
    {
        printf("1\n");
        return;
    }
    if(s<2||s>9*n||(n%2==0&&s%2==1))
    {
        printf("-1\n");
        return;
    }
    ans[n]=0;
    for(int i=0;i<n/2;i++)
        for(int j=9;j>=0;j--)
            if(s-sum-2*j>=0&&s-sum-2*j<=9*(n-2*i-2))
            {
                sum+=2*j;
                ans[i]=ans[n-i-1]='0'+j;
                break;
            }
    if(n&1) ans[n/2]=s-sum+'0';
    for(int i=0;i<n;i++) printf("%c",ans[i]);
    printf("\n");
    //printf("%s\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
