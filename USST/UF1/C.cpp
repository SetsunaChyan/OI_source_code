#include <bits/stdc++.h>
using namespace std;

struct P
{
    int x,r,pos;
}p[10005];
int n,m,tmp[10005],ans[200005],fst;

bool cmp(P a,P b)
{
    return a.x<b.x;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].x,&p[i].r),p[i].pos=i;
    p[n].x=20010,p[n].r=0,p[n].pos=n;
    sort(p,p+n+1,cmp);
    for(int i=0;i<=n;i++) tmp[i]=p[i].x,ans[i]=0x3f3f3f3f;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int x,y,flag=0;
        scanf("%d%d",&x,&y);
        int k=lower_bound(tmp,tmp+1+n,x)-tmp;
        if(k!=0)
        {
            k--;
            if((x-p[k].x)*(x-p[k].x)+y*y<=p[k].r*p[k].r)
            {
                if(ans[p[k].pos]==0x3f3f3f3f) fst++;
                flag++;
                ans[p[k].pos]=min(ans[p[k].pos],i+1);
            }
            k++;
        }
        if((x-p[k].x)*(x-p[k].x)+y*y<=p[k].r*p[k].r)
        {
            if(ans[p[k].pos]==0x3f3f3f3f) fst++;
            if(!flag) flag++;
            ans[p[k].pos]=min(ans[p[k].pos],i+1);
        }
        k++;
        if((x-p[k].x)*(x-p[k].x)+y*y<=p[k].r*p[k].r)
        {
            if(ans[p[k].pos]==0x3f3f3f3f) fst++;
            ans[p[k].pos]=min(ans[p[k].pos],i+1);
        }
    }
    printf("%d\n",fst);
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]!=0x3f3f3f3f?ans[i]:-1);
    return 0;
}
