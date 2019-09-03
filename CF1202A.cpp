#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char a[100005],b[100005];
int l1,l2;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s%s",a,b);
        l1=strlen(a),l2=strlen(b);
        int ans,t;
        for(int i=l2-1;i>=0;i--)
            if(b[i]=='1')
            {
                t=i;
                break;
            }
        for(int i=l1-(l2-t);i>=0;i--)
            if(a[i]=='1')
            {
                ans=l1-(l2-t)-i;
                break;
            }
        printf("%d\n",ans);
    }

    return 0;
}
