#include <bits/stdc++.h>
using namespace std;

int n,m,ans=0,x[100005],y[100005],pa=0,pb=0,wha=0,whb=0;
struct node
{
    char c;
    int pos;
}a[100005],b[100005];

inline bool cmp(node a,node b){return a.c>b.c;}

int main()
{
    scanf("%d%d ",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%c",&a[i].c),a[i].pos=i+1;
        if(a[i].c=='?') wha++;
    }
    getchar();
    for(int i=0;i<m;i++)
    {
        scanf("%c",&b[i].c),b[i].pos=i+1;
        if(b[i].c=='?') whb++;
    }
    sort(a,a+n,cmp);
    sort(b,b+m,cmp);
    int ua,ub;
    ua=ub=0;
    while(pa<n-wha&&pb<m-whb)
    {
        if(a[pa].c==b[pb].c)
        {
            x[ans]=a[pa].pos;
            y[ans]=b[pb].pos;
            ans++,pa++,pb++;
        }
        else if(a[pa].c<b[pb].c)
        {
            if(ua<wha)
            {
                x[ans]=a[n-wha+ua].pos;
                y[ans]=b[pb].pos;
                ua++,ans++;
            }
            pb++;
        }
        else if(a[pa].c>b[pb].c)
        {
            if(ub<whb)
            {
                x[ans]=a[pa].pos;
                y[ans]=b[m-whb+ub].pos;
                ub++,ans++;
            }
            pa++;
        }
    }
    while(pa<n-wha&&ub<whb)
    {
        x[ans]=a[pa].pos;
        y[ans]=b[m-whb+ub].pos;
        pa++,ub++,ans++;
    }
    while(pb<m-whb&&ua<wha)
    {
        x[ans]=a[n-wha+ua].pos;
        y[ans]=b[pb].pos;
        pb++,ua++,ans++;
    }
    while(ua<wha&&ub<whb)
    {
        x[ans]=a[n-wha+ua].pos;
        y[ans]=b[m-whb+ub].pos;
        ua++,ub++,ans++;
    }
    printf("%d\n",ans);
    for(int i=0;i<ans;i++)
        printf("%d %d\n",x[i],y[i]);
    return 0;
}