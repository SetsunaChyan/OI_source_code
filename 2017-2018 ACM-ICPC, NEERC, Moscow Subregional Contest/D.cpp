#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int n;
vector<llu> v;

int main()
{
    scanf("%d",&n);
    llu tmp,x,t;
    while(n--)
    {
        scanf("%llu",&x);
        v.push_back(x);
        if(x>=128) continue;
        tmp=0;t=1;
        for(int i=v.size()-2;i>=0;i--)
            tmp*=128,tmp+=(v[i]-128),t*=128;
        tmp+=t*v[v.size()-1];
        //printf("! %llu %llu\n",tmp,tmp+1);
        v.clear();
        if((tmp&1)&&tmp+1==0) printf("-%llu\n",(tmp-1)/2+1);
        else if(tmp&1) printf("-%llu\n",(tmp+1)/2);
        else printf("%llu\n",tmp/2);
    }
    return 0;
}
