#include <bits/stdc++.h>
using namespace std;

struct node
{
    int pos,x[105],y;
}a[105];
vector<int> ans,tmp;
int n,m,p,q;

inline bool cmp(node a,node b)
{
    return a.x[0]-a.y<b.x[0]-b.y;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        a[i].pos=i;
        for(int j=1,s;j<n;j++)
            scanf("%d",&a[i].x[j]);
        scanf("%d",&a[i].y);
        ans.push_back(i);
    }
    for(int i=1;i<n;i++)
    {
        p=q=0;tmp.clear();
        for(int j=1;j<=m;j++)
        {
            a[j].x[0]=a[j].x[i];
            p+=a[j].x[0],q+=a[j].y;
        }
        sort(a+1,a+1+m,cmp);
        for(int j=1;j<=m;j++)
        {
            if(p>=q) break;
            tmp.push_back(a[j].pos);
            p-=a[j].x[0],q-=a[j].y;
        }
        //printf("%d %d\n",p,q);
        if(tmp.size()<ans.size()) ans=tmp;
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d ",p);
    return 0;
}
