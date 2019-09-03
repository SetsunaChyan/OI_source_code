#include <bits/stdc++.h>
using namespace std;
int n,ma,qaq,vis[22],ww[102];
set<int>s;
vector<int>a,ss;
map<vector<int>,int>h;
void init()
{
    for(int n5=0;n5<4&&n5*5<20;n5++)//5
        for(int n2=0;n2<=10&&2*n2+5*n5<20;n2++)
            for(int n1=0;n1<=20&&n1+2*n2+5*n5<20;n1++)
            {
                //printf("n1 %d n2 %d n5 %d\n",n1,n2,n5);
                a.clear();
                for(int i=1;i<=n5;i++)a.push_back(5);
                for(int i=1;i<=n2;i++)a.push_back(2);
                for(int i=1;i<=n1;i++)a.push_back(1);
                memset(vis,0,sizeof(vis));
                vis[0]=1;
                for(auto v:a)
                    for(int i=19;i>=v;i--)
                        vis[i]|=vis[i-v];
                ss.clear();
                for(int i=1;i<=19;i++)
                    if(vis[i])
                        ss.push_back(i);
                if(h.find(ss)!=h.end())
                    h[ss]=min(h[ss],n1+n2+n5);
                else
                    h[ss]=n1+n2+n5;
            }

}
int main()
{
    init();
    //printf("%d\n",h.size());//54
    int _;scanf("%d",&_);
    while(_--)
    {
        ma=qaq=0;
        s.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",ww+i),qaq+=ww[i]%10;
        if(qaq)
        {printf("-1\n");continue;}
        for(int i=1,w;i<=n;i++)
        {
            w=ww[i],ma=max(ma,w/100);
            if(w/10%10)
                s.insert(w/10%10);
        }
        int ans1=1e9,ans2=1e9;
        for(auto &p:h)
        {
            if(p.first.size()<s.size())continue;
            for(auto c:s)
                if(find(p.first.begin(),p.first.end(),c)==p.first.end())
                    goto f;
            ans1=min(ans1,p.second);
            f:;
        }
        if(ma)
        {
            s.clear();
            for(int i=1,w;i<=n;i++)
            {
                w=ww[i];
                if(w/100==ma)
                {
                    w-=(ma-1)*100;
                    w/=10;
                    if(w)s.insert(w);
                }
                else
                {
                    if(w/10%10)
                        s.insert(w/10%10);
                }
            }
            for(auto &p:h)
            {
                if(p.first.size()<s.size())continue;
                for(auto c:s)
                    if(find(p.first.begin(),p.first.end(),c)==p.first.end())
                        goto f2;
                ans2=min(ans2,p.second);
                f2:;
            }
        }
        //printf("%d %d\n",ans1,ans2);
        printf("%d\n",min(ans1+ma,ans2+ma-1));
    }
    return 0;
}
