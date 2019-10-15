#include <bits/stdc++.h>
using namespace std;

int s,p,ans;

int main()
{
    scanf("%d%d",&s,&p);
    p-=s;
    if(p<=0) ans=0;
    else if(p<5*60) ans=1;
    else if(p<15*60) ans=2;
    else if(p<30*60) ans=3;
    else ans=4;
    printf("%d",ans);
    return 0;
}
