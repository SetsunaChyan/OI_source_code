#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
inline int read()
{
   int s=0;
   char ch=getchar();
   while(ch<'0'||ch>'9')ch=getchar();
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s;
}
int n,m,w;
map<int,int>q,del;
int main()
{
    int _;scanf("%d",&_);
    while(_--)
    {
        q.clear();
        del.clear();
        ll all=0,delall=0;
        int ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w);
            all+=w;
            while(all-delall>m)
            {
                //if(q.empty()) break;
                if(q.empty()) assert(0);
                pair<int,int> x=*q.rbegin();
                if(all-delall-(ll)x.first*x.second>m)
                {
                    q.erase(x.first);
                    del[x.first]+=x.second;
                    ans+=x.second;
                    delall+=(ll)x.first*x.second;
                }
                else
                {
                    int k=((all-delall)-m)/x.first;
                    if((all-delall-m)%x.first) k++;
                    del[x.first]+=k;
                    if(x.second==k)
                        q.erase(x.first);
                    else
                        q[x.first]-=k;
                    ans+=k;
                    delall+=(ll)x.first*k;
                }
            }
            while(!q.empty()&&!del.empty()&&(*q.rbegin()).first>(*del.begin()).first)
            {
                pair<int,int> x=*q.rbegin();
                pair<int,int> y=*del.begin();
                delall-=y.first;
                delall+=x.first;
                if(x.second==1)q.erase(x.first);
                else q[x.first]--;
                if(y.second==1)del.erase(y.first);
                else del[y.first]--;
                q[y.first]++;
                del[x.first]++;
                //printf("qpop:%d delpop:%d\n",x,y);
            }
            while(!del.empty()&&all-delall+(*del.begin()).first<=m)
            {
                pair<int,int> x=*del.begin();
                if(all-delall+(ll)x.first*x.second<=m)
                {
                    del.erase(x.first);
                    q[x.first]+=x.second;
                    delall-=(ll)x.first*x.second;
                    ans-=x.second;
                }
                else
                {
                    int k=(m-all+delall)/x.first;
                    if((m-all+delall)%x.first) k++;
                    if(x.second==k)
                        del.erase(x.first);
                    else
                        del[x.first]-=k;
                    delall-=(ll)x.first*k;
                    ans-=k;
                }
            }
            printf("%d ",ans);
            /*printf("!%d!%d! ",q.size(),del.size());
            for(auto x:q)
                printf("q %d:%d\n",x.first,x.second);
            for(auto x:del)
                printf("d %d:%d\n",x.first,x.second);*/
            q[w]++;
        }
        puts("");
    }
    return 0;
}
