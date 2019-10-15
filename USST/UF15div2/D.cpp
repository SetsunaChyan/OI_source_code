#include <bits/stdc++.h>
using namespace std;

int x1,x2,y1,y2,a1,a2,b1,b2,n,ret;

bool f(int x1,int y1,int x2,int y2)
{
    if(y2<b2) return false;
    if(y1>b1) return false;
    if(x2<a2) return false;
    if(x1>a1) return false;
    return true;
}

bool check(int x1,int y1,int x2,int y2)
{
    if(x1>x2) return false;
    if(y1>y2) return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    int l=1,r=n;
    y2=1;y1=n;x2=1;x1=n;
    for(int i=1<<16;i;i/=2)
    {
        if(y2+i>n) continue;
        if(!check(1,1,n,y2+i)) continue;
        printf("? %d %d %d %d\n",1,1,n,y2+i);
        fflush(stdout);
        scanf("%d",&ret);
        if(!ret) y2+=i;
    }
    y2++;y1=y2+1;
    for(int i=1<<16;i;i/=2)
    {
        if(y1-i<=0) continue;
        if(!check(1,y1-i,n,y2)) continue;
        printf("? %d %d %d %d\n",1,y1-i,n,y2);
        fflush(stdout);
        scanf("%d",&ret);
        if(!ret) y1-=i;
    }
    y1--;
    //qaq
    for(int i=1<<16;i;i/=2)
    {
        if(x2+i>n) continue;
        if(!check(1,y1,x2+i,y2)) continue;
        printf("? %d %d %d %d\n",1,y1,x2+i,y2);
        fflush(stdout);
        scanf("%d",&ret);
        if(!ret) x2+=i;
    }
    x2++;x1=x2+1;
    for(int i=1<<16;i;i/=2)
    {
        if(x1-i<=0) continue;
        if(!check(x1-i,y1,x2,y2)) continue;
        printf("? %d %d %d %d\n",x1-i,y1,x2,y2);
        fflush(stdout);
        scanf("%d",&ret);
        if(!ret) x1-=i;
    }
    x1--;
    a1=x1,a2=x2,b1=y1,b2=y2;
    y2=1;y1=n;x2=1;x1=n;

    //printf("!!\n");

    for(int i=1<<16;i;i/=2)
    {
        if(y2+i>n) continue;
        if(!check(1,1,n,y2+i)) continue;
        printf("? %d %d %d %d\n",1,1,n,y2+i);
        fflush(stdout);
        scanf("%d",&ret);
        if(f(1,1,n,y2+i)) ret--;
        //printf("@ %d\n",ret);
        if(!ret) y2+=i;
    }
    y2++;y1=y2+1;
    for(int i=1<<16;i;i/=2)
    {
        if(y1-i<=0) continue;
        if(!check(1,y1-i,n,y2)) continue;
        printf("? %d %d %d %d\n",1,y1-i,n,y2);
        fflush(stdout);
        scanf("%d",&ret);
        if(f(1,y1-i,n,y2)) ret--;
        if(!ret) y1-=i;
    }
    y1--;
    //qaq
    for(int i=1<<16;i;i/=2)
    {
        if(x2+i>n) continue;
        if(!check(1,y1,x2+i,y2)) continue;
        printf("? %d %d %d %d\n",1,y1,x2+i,y2);
        fflush(stdout);
        scanf("%d",&ret);
        if(f(1,y1,x2+i,y2)) ret--;
        if(!ret) x2+=i;
    }
    x2++;x1=x2+1;
    for(int i=1<<16;i;i/=2)
    {
        if(x1-i<=0) continue;
        if(!check(x1-i,y1,x2,y2)) continue;

        printf("? %d %d %d %d\n",x1-i,y1,x2,y2);
        fflush(stdout);
        scanf("%d",&ret);
        if(f(x1-i,y1,x2,y2)) ret--;
        if(!ret) x1-=i;
    }
    x1--;
    printf("! %d %d %d %d %d %d %d %d\n",a1,b1,a2,b2,x1,y1,x2,y2);
    fflush(stdout);
    return 0;
}
