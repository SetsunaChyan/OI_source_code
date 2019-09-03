#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x,y,x1,y1,x2,y2,ans,cntx1,cntx2,cnty1,cnty2;
char s[200005];

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        x1=y1=0;
        x=y=x2=y2=ans=0;
        cntx1=cntx2=cnty1=cnty2=0;
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<l;i++)
        {
            if(s[i]=='W') x+=1;
            else if(s[i]=='S') x-=1;
            else if(s[i]=='A') y+=1;
            else y-=1;
            //printf("qaq %lld %lld\n",x,y);
            if(s[i]=='W'||s[i]=='S')
            {
                if(x<x1) x1=x,cntx1=1; else if(x==x1) cntx1++;
                if(x>x2) x2=x,cntx2=1; else if(x==x2) cntx2++;
                continue;
            }
            if(y<y1) y1=y,cnty1=1; else if(y==y1) cnty1++;
            if(y>y2) y2=y,cnty2=1; else if(y==y2) cnty2++;
        }
        ans=(x2-x1+1)*(y2-y1+1);
        if(x2-x1>1&&(cntx1==1||cntx2==1)) ans=min(ans,(x2-x1)*(y2-y1+1));
        if(y2-y1>1&&(cnty1==1||cnty2==1)) ans=min(ans,(x2-x1+1)*(y2-y1));
        printf("%lld\n",ans);
        //printf("%lld %lld %lld %lld\n",x1,x2,y1,y2);
        //printf("%lld %lld %lld %lld\n",cntx1,cntx2,cnty1,cnty2);
        /*AWDWAWD*/
    }
    return 0;
}
