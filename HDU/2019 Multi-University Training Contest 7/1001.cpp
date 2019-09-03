#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
typedef long long ll;

const int mod=10;
const int yw=1;
ll a[100005],b[100005],c[100005],res[200005];
char as[100005],bs[100005],cs[100005];
int la,lb,lc;
bool check(int x,int y,int z)
{
    //if(x!=0&&x%1000==0||y!=0&&y%1000==0||z!=0&&z%1000==0)
        //printf("%d %d %d\n",x,y,z);
    //getch();
    if(x<0||y<0||z<0)return false;
    if(la+x>lc+z||lb+y>lc+z||lc+z-(la+x)>1&&lc+z-(lb+y)>1)return false;
    int jw=0,i,aa,bb,cc;
    for(i=0;i<min(la+x,lb+y);i++)
    {
        if(i<x)aa=0;else aa=a[i-x];
        if(i<y)bb=0;else bb=b[i-y];
        res[i]=(aa+bb+jw)%mod;
        jw=(aa+bb+jw)/mod;
        if(i<z)cc=0;else cc=c[i-z];
        if(cc!=res[i])return false;
    }
    for(;i<la+x;i++)
    {
        res[i]=(a[i-x]+jw)%mod,jw=(a[i-x]+jw)/mod;
        if(i<z)cc=0;else cc=c[i-z];
        if(cc!=res[i])return false;
    }
    for(;i<lb+y;i++)
    {
        res[i]=(b[i-y]+jw)%mod,jw=(b[i-y]+jw)/mod;
        if(i<z)cc=0;else cc=c[i-z];
        if(cc!=res[i])return false;
    }
    /*printf("%d ",jw);
    for(int j=i;j>=0;j--)
        printf("%d",res[j]);
    puts("");*/
    if(jw)
    {
        res[i]=jw;
        if(i<z)cc=0;else cc=c[i-z];
        if(cc!=res[i])return false;
        return lc+z==i+1;
    }
    return lc+z==i;
}

int main()
{
    //freopen("1.txt","r",stdin);
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%s%s%s",as,bs,cs);
        la=strlen(as),lb=strlen(bs),lc=strlen(cs);
        reverse(as,as+la);reverse(bs,bs+lb);reverse(cs,cs+lc);
        for(int i=0;i<la;i+=yw)
            for(int j=0;j<yw&&i+j<la;j++)
            {
                a[i]*=10;
                a[i]+=as[i+j]-'0';
            }
        for(int i=0;i<lb;i+=yw)
            for(int j=0;j<yw&&i+j<lb;j++)
            {
                b[i]*=10;
                b[i]=bs[i+j]-'0';
            }
        for(int i=0;i<lc;i+=yw)
            for(int j=0;j<yw&&i+j<lc;j++)
            {
                c[i]*=10;
                c[i]=cs[i+j]-'0';
            }
        la=(la-1)/yw+1;
        lb=(lb-1)/yw+1;
        lc=(lc-1)/yw+1;
        //for(int i=0;i<la;i++)printf("%d",a[i]);

        //z==0
        for(int x=0;x>=-1;x--)
            for(int y=0;y<=lc-lb;y++)
                if(check(lc-la+x,y,0))
                    {printf("%d %d 0\n",lc-la+x,y);goto ok;}
        for(int y=0;y>=-1;y--)
            for(int x=0;x<=lc-la;x++)
                if(check(x,lc-lb+y,0))
                    {printf("%d %d 0\n",x,lc-lb+y);goto ok;}
        //xy==0
        //puts("y==0");
        for(int z=max(0,la-lc);z<=lb;z++)
        {
            if(lc+z-lb==0||lc+z-lb==1)
                for(int x=0;x<=lc+z-la;x++)
                    if(check(x,0,z))
                        {printf("%d %d %d\n",x,0,z);goto ok;}
            if(check(lc+z-la,0,z))
                {printf("%d %d %d\n",lc+z-la,0,z);goto ok;}
            if(check(lc+z-la-1,0,z))
                {printf("%d %d %d\n",lc+z-la-1,0,z);goto ok;}
        }
        //puts("x==0");
        for(int z=max(0,lb-lc);z<=la;z++)
        {
            if(lc+z-la==0||lc+z-la==1)
                for(int y=0;y<=lc+z-lb;y++)
                    if(check(0,y,z))
                        {printf("%d %d %d\n",0,y,z);goto ok;}
            if(check(0,lc+z-lb,z))
                {printf("%d %d %d\n",0,lc+z-lb,z);goto ok;}
            if(check(0,lc+z-lb-1,z))
                {printf("%d %d %d\n",0,lc+z-lb-1,z);goto ok;}
        }
        puts("-1");
        ok:;
    }
    return 0;
}
