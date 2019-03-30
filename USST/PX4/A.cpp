#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct node
{
    int a,b,c,d;
    friend bool operator < (node x,node y) {return x.c>y.c;}
}tmp;
priority_queue<node> q;
int n,a[100005],b[100005];


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    sort(a,a+n);sort(b,b+n);
    tmp.a=tmp.b=0,tmp.c=a[0]+b[0],tmp.d=1;
    q.push(tmp);
    for(int k=0;k<n;k++)
    {
        tmp=q.top();
        q.pop();
        printf("%d ",tmp.c);
        if(tmp.d)
        {
            if(tmp.a+1<n) q.push((node){tmp.a+1,tmp.b,a[tmp.a+1]+b[tmp.b],1});
            if(tmp.b+1<n) q.push((node){tmp.a,tmp.b+1,a[tmp.a]+b[tmp.b+1],0});
        }
        else
            if(tmp.b+1<n) q.push((node){tmp.a,tmp.b+1,a[tmp.a]+b[tmp.b+1],0});
    }
    return 0;
}