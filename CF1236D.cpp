#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,k,rl,rr,cl,cr;
ll sum;
set<int> sr[100005],sc[100005];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    rl=0,rr=n+1,cl=0,cr=m+1;
    sum=(long long)n*m-k-1;
    for(int i=0;i<=n;i++) sr[i].insert(0),sr[i].insert(m+1);
    for(int i=0;i<=m;i++) sc[i].insert(0),sc[i].insert(n+1);
    for(int i=0,x,y;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        sr[x].insert(y);
        sc[y].insert(x);
    }
    if(sum-n+sc[1].size()-1==0)
    {
        printf("Yes");
        return 0;
    }
    int nowx=1,nowy=1,dir=1;
    for(int i=0;i<n+m;i++)
    {
        int tmp,lastx=nowx,lasty=nowy;
        if(dir==1)
        {
            tmp=min(cr,*sr[nowx].lower_bound(nowy));
            sum-=tmp-nowy-1;
            nowy=tmp-1;
            cr=nowy;
            rl=nowx;
        }
        else if(dir==2)
        {
            tmp=min(rr,*sc[nowy].lower_bound(nowx));
            sum-=tmp-nowx-1;
            nowx=tmp-1;
            cr=nowy;
            rr=nowx;
        }
        else if(dir==3)
        {
            auto it=sr[nowx].lower_bound(nowy);
            it--;
            tmp=max(cl,*it);
            sum-=nowy-tmp-1;
            nowy=tmp+1;
            cl=nowy;
            rr=nowx;
        }
        else
        {
            auto it=sc[nowy].lower_bound(nowx);
            it--;
            tmp=max(rl,*it);
            sum-=nowx-tmp-1;
            nowx=tmp+1;
            cl=nowy;
            rl=nowx;
        }
        //printf("! %d %d %d %lld\n",nowx,nowy,dir,sum);
        if(lastx==nowx&&lasty==nowy) break;
        dir++;
        if(dir==5) dir=1;
    }
    if(sum) printf("No");
    else printf("Yes");
    return 0;
}
