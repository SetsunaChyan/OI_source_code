#include <bits/stdc++.h>
using namespace std;

int n,ans,a[2005];
set<int> s;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    ans=n;
    for(int i=0;i<=n;i++)
    {
        int flag=0;
        s.clear();
        for(int j=0;j<i;j++)
            if(s.find(a[j])==s.end()) s.insert(a[j]);
            else
            {
                ans=min(ans,n-j);
                flag=1;
                break;
            }
        if(flag) break;
        for(int j=n-1;j>=i;j--)
        {
            if(s.find(a[j])==s.end()) s.insert(a[j]);
            else
            {
                ans=min(ans,j-i+1);
                break;
            }
            if(i==j) ans=0;
        }
        if(ans==0) break;
    }
    printf("%d",ans);
    return 0;
}
