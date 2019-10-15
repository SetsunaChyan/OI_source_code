#include <bits/stdc++.h>
using namespace std;

const double eps=1e-6;
int x[8],y[8];
int xx[4],yy[4],cnt,qaq[4];

int dis(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

bool issq(int a0,int a1,int a2,int a3)
{
    if(dis(x[a0],y[a0],x[a3],y[a3])==dis(x[a2],y[a2],x[a1],y[a1])&&dis(x[a0],y[a0],x[a2],y[a2])==dis(x[a1],y[a1],x[a3],y[a3])&&dis(x[a0],y[a0],x[a1],y[a1])==dis(x[a2],y[a2],x[a3],y[a3]))
    {
        if(dis(x[a0],y[a0],x[a1],y[a1])==dis(x[a0],y[a0],x[a2],y[a2])&&dis(x[a0],y[a0],x[a1],y[a1])==dis(x[a3],y[a3],x[a2],y[a2])&&dis(x[a0],y[a0],x[a1],y[a1])==dis(x[a3],y[a3],x[a1],y[a1]))
            return true;
        if(dis(x[a0],y[a0],x[a1],y[a1])==dis(x[a0],y[a0],x[a3],y[a3])&&dis(x[a0],y[a0],x[a1],y[a1])==dis(x[a3],y[a3],x[a2],y[a2])&&dis(x[a0],y[a0],x[a1],y[a1])==dis(x[a1],y[a1],x[a2],y[a2]))
            return true;
        if(dis(x[a0],y[a0],x[a2],y[a2])==dis(x[a0],y[a0],x[a3],y[a3])&&dis(x[a0],y[a0],x[a2],y[a2])==dis(x[a3],y[a3],x[a1],y[a1])&&dis(x[a0],y[a0],x[a2],y[a2])==dis(x[a1],y[a1],x[a2],y[a2]))
            return true;
    }
    return false;
}

bool isrec(int a,int b,int c,int d)
{
    cnt=0;
    for(int i=0;i<8;i++)
        if(i!=a&&i!=b&&i!=c&&i!=d)
            xx[cnt]=x[i],yy[cnt]=y[i],qaq[cnt]=i,cnt++;
    if(dis(xx[0],yy[0],xx[3],yy[3])==dis(xx[2],yy[2],xx[1],yy[1])&&dis(xx[0],yy[0],xx[2],yy[2])==dis(xx[1],yy[1],xx[3],yy[3])&&dis(xx[0],yy[0],xx[1],yy[1])==dis(xx[2],yy[2],xx[3],yy[3]))
        return true;
    return false;
}

int main()
{
    for(int i=0;i<8;i++)
        scanf("%d%d",x+i,y+i);
    for(int i=0;i<8;i++)
        for(int j=i+1;j<8;j++)
            for(int k=j+1;k<8;k++)
                for(int l=k+1;l<8;l++)
                    if(issq(i,j,k,l)&&isrec(i,j,k,l))
                    {
                        printf("YES\n");
                        printf("%d %d %d %d\n",i+1,j+1,k+1,l+1);
                        printf("%d %d %d %d\n",qaq[0]+1,qaq[1]+1,qaq[2]+1,qaq[3]+1);
                        return 0;
                    }
    printf("NO");
    return 0;
}
