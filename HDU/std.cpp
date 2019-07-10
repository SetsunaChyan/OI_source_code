#include <iostream>

#include <algorithm>

#include <math.h>

#include <string.h>

#include <stdlib.h>

using namespace std;

struct node

{

    double l,r,h;

    int f;

}a[5000];

struct nodee

{

    double s,ss;

    int cnt;

}t[5000];

double has[5000];

bool cmp(node x,node y)

{

    return x.h<y.h;

}

void build(int l,int r,int n)

{

    t[n].ss=0;

    t[n].s=0;

    t[n].cnt=0;

    if(l==r)

        return;

    int mid=(l+r)/2;

    build(l,mid,n*2);

    build(mid+1,r,n*2+1);

}

int find(double x,int l,int r)//二分查找在has中的编号

{

    while(l<=r)

    {

        int mid=(l+r)/2;

        if(has[mid]==x)

            return mid;

        if(has[mid]<x)

            l=mid+1;

        else

            r=mid-1;

    }

    return -1;

}

void pushup(int k,int l,int r)//用来跟新sum

{

    if(t[k].cnt)//编号为k的整个范围都可以算面积，直接has[r+1]-has[l]

        t[k].s=has[r+1]-has[l];

    else if(l==r)//到了叶子节点

        t[k].s=0;

    else//不是叶子节点

        t[k].s=t[k*2+1].s+t[k*2].s;



    if(t[k].cnt>1)

        t[k].ss=has[r+1]-has[l];

    else if(l==r)

        t[k].ss=0;

    else if(t[k].cnt==1)

        t[k].ss=t[k*2].s+t[k*2+1].s;

    else

        t[k].ss=t[k*2].ss+t[k*2+1].ss;

}

void updata(int k,int l,int r,int x,int y,int flag)//用来查找和跟新

{

    if(l==x&&r==y)

    {

        t[k].cnt+=flag;

        pushup(k,l,r);

        return;

    }

    int mid=(l+r)/2;

    if(mid>=y)

        updata(k*2,l,mid,x,y,flag);

    else if(mid<x)

        updata(k*2+1,mid+1,r,x,y,flag);

    else

    {

        updata(k*2,l,mid,x,mid,flag);

        updata(k*2+1,mid+1,r,mid+1,y,flag);

    }

    pushup(k,l,r);

}

int main()

{

    int n;

    double x1,y1,x2,y2;

    double ans;

    int test;

    scanf("%d",&test);

    while(test--)

    {

        scanf("%d",&n);

        memset(t,0,sizeof(t));

        //memset(sum,0,sizeof(sum));

        ans=0.0;

        for(int i=1;i<=n;i++)

        {

            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);

            a[i*2].l=x1+1;

            a[i*2].r=x2+1;

            a[i*2].h=y2+1;

            a[i*2].f=-1;

            has[i*2]=x2+1;



            a[2*i-1].l=x1+1;

            a[i*2-1].r=x2+1;

            a[i*2-1].h=y1+1;

            a[i*2-1].f=1;

            has[i*2-1]=x1+1;

        }

        sort(has+1,has+2*n+1);

        sort(a+1,a+1+2*n,cmp);

        int m=1;

        for(int i=1; i<=n*2; i++)

            if(has[i]!=has[i-1])

                has[m++]=has[i];

        build(1,m-1,1);

        for(int i=1;i<=2*n;i++)

        {

            int l=find(a[i].l,1,m);

            int r=find(a[i].r,1,m)-1;

            if(l<=r)

                updata(1,1,2*n,l,r,a[i].f);

            ans+=t[1].ss*(a[i+1].h-a[i].h);

        }

        printf("%.2lf\n",ans);

    }

    return 0;

}

