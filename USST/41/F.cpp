#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node
{
    ll x,y;
}a[300005];
ll mul=1,maxadd=-0x3f3f3f3f3f3f3f3fll,sum=0;
int n,q,w,num=0;

bool cmp(node a,node b){return a.x-a.y>b.x-b.y;};

int main()
{
    scanf("%d%d%d",&n,&q,&w);
    for(int i=0;i<q;i++) mul*=2;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        if(w==1&&a[i].x*mul-a[i].y>maxadd)
        {
            maxadd=a[i].x*mul-a[i].y;
            num=i;
        }
        if(w>1&&max(a[num].x,a[num].y)+max(a[i].x*mul,a[i].y)>max(a[num].x*mul,a[num].y)+max(a[i].x,a[i].y))
            num=i;
    }
    a[num].x*=mul;
    sort(a,a+n,cmp);
    for(int i=0;i<w;i++)
        if(a[i].y<a[i].x) a[i].y=a[i].x;
    printf("%lld",sum);
    return 0;
} 

/*
8 3 22693
104 127
32 34
69 65
28 25
97 81
125 68
91 15
121 9

*/