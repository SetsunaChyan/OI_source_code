#include <bits/stdc++.h>
using namespace std;

int x1,x2,y1,y2,a1,a2,b1,b2,n,ret;
int xx1[2],yy1[2],xx2[2],yy2[2];

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
    //return true;
    printf("@@ %d %d %d %d %d\n",x1,y1,x2,y2,x1<=x2&&y1<=y2);
    if(x1<=x2&&y1<=y2) return true;
    return false;
}

int get(int x1,int y1,int x2,int y2)
{
    int ret=0;
    for(int i=0;i<2;i++)
    {
        int flag=1;
        if(y2<yy2[i]) flag=0;
        if(y1>yy1[i]) flag=0;
        if(x2<xx2[i]) flag=0;
        if(x1>xx1[i]) flag=0;
        ret+=flag;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    scanf("%d%d%d%d",&xx1[0],&yy1[0],&xx2[0],&yy2[0]);
    scanf("%d%d%d%d",&xx1[1],&yy1[1],&xx2[1],&yy2[1]);
    int l=1,r=n;
    y2=1;y1=n;x2=1;x1=n;
    for(int i=1<<16;i>-1;i?i>>=1:i--)
    {
        if(y2+i>n) continue;
        if(!check(1,1,n,y2+i)) continue;
        printf("? %d %d %d %d\n",1,1,n,y2+i);
        printf("@ y2\n");
        fflush(stdout);
        ret=get(1,1,n,y2+i);
        if(!ret) y2+=i;
        if(i==0) break;
    }
    y2++;y1=y2+1;
    for(int i=1<<16;i>-1;i?i>>=1:i--)
    {
        if(y1-i<=0) continue;
        if(!check(1,y1-i,n,y2)) continue;
        printf("? %d %d %d %d\n",1,y1-i,n,y2);
        printf("@ y1\n");
        fflush(stdout);
        ret=get(1,y1-i,n,y2);
        if(!ret) y1-=i;
        if(i==0) break;
    }
    y1--;
    //qaq
    for(int i=1<<16;i>-1;i?i>>=1:i--)
    {
        if(x2+i>n) continue;
        if(!check(1,y1,x2+i,y2)) continue;
        printf("? %d %d %d %d\n",1,y1,x2+i,y2);
        printf("@ x2\n");
        fflush(stdout);
        ret=get(1,y1,x2+i,y2);
        if(!ret) x2+=i;
        if(i==0) break;
    }
    x2++;x1=x2+1;
    for(int i=1<<16;i>-1;i?i>>=1:i--)
    {
        if(x1-i<=0) continue;
        if(!check(x1-i,y1,x2,y2)) continue;
        printf("? %d %d %d %d\n",x1-i,y1,x2,y2);
        printf("@ x1\n");
        fflush(stdout);
        ret=get(x1-i,y1,x2,y2);
        if(!ret) x1-=i;
        if(i==0) break;
    }
    x1--;
    a1=x1,a2=x2,b1=y1,b2=y2;
    y2=1;y1=n;x2=1;x1=n;

    //printf("!!\n");

    for(int i=1<<16;i>-1;i?i>>=1:i--)
    {
        if(y2+i>n) continue;
        if(!check(1,1,n,y2+i)) continue;
        printf("? %d %d %d %d\n",1,1,n,y2+i);
        fflush(stdout);
        ret=get(1,1,n,y2+i);
        if(f(1,1,n,y2+i)) ret--;
        //printf("@ %d\n",ret);
        if(!ret) y2+=i;
        if(i==0) break;
    }
    y2++;y1=y2+1;
    for(int i=1<<16;i>-1;i?i>>=1:i--)
    {
        if(y1-i<=0) continue;
        if(!check(1,y1-i,n,y2)) continue;
        printf("? %d %d %d %d\n",1,y1-i,n,y2);
        fflush(stdout);
        ret=get(1,y1-i,n,y2);
        if(f(1,y1-i,n,y2)) ret--;
        if(!ret) y1-=i;
        if(i==0) break;
    }
    y1--;
    //qaq
    for(int i=1<<16;i>-1;i?i>>=1:i--)
    {
        if(x2+i>n) continue;
        if(!check(1,y1,x2+i,y2)) continue;
        printf("? %d %d %d %d\n",1,y1,x2+i,y2);
        fflush(stdout);
        ret=get(1,y1,x2+i,y2);
        if(f(1,y1,x2+i,y2)) ret--;
        if(!ret) x2+=i;
        if(i==0) break;
    }
    x2++;x1=x2+1;
    for(int i=1<<16;i>-1;i?i<<=1:i--)
    {
        if(x1-i<=0) continue;
        if(!check(x1-i,y1,x2,y2)) continue;
        printf("? %d %d %d %d\n",x1-i,y1,x2,y2);
        fflush(stdout);
        ret=get(x1-i,y1,x2,y2);
        if(f(x1-i,y1,x2,y2)) ret--;
        if(!ret) x1-=i;
    }
    x1--;
    printf("! %d %d %d %d %d %d %d %d\n",a1,b1,a2,b2,x1,y1,x2,y2);
    return 0;
}
