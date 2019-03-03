#include <cstdio>
#include <cmath>

int wvx[10005],wvy[10005],t[10005],ax,bx,ay,by,k,v,n,tx,ty;
double vx,vy,nx,ny;

int main()
{
    scanf("%d%d%d%d",&ax,&ay,&bx,&by);
    scanf("%d%d%d",&n,&k,&v);
    wvx[0]=wvy[0]=0;
    t[n+1]=k;
    tx=ax-bx,ty=ay-by;
    nx=ax,ny=ay;
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&t[i],&wvx[i],&wvy[i]);
    for(int i=1;i<=n;i++)
    {
        tx+=(t[i+1]-t[i])*wvx[i];
        ty+=(t[i+1]-t[i])*wvy[i];
    }
    if(sqrt((double)tx*tx+(double)ty*ty)>v*k)
    {
        printf("No");
        return 0;
    }
    printf("Yes\n");
    vx=-(double)tx/k;
    vy=-(double)ty/k;
    int g=1;
    for(int i=0;i<k;i++)
    {
        if(i==t[g+1]) g++;
        nx+=vx+wvx[g];ny+=vy+wvy[g];
        printf("%lf %lf\n",nx,ny);
    }
    return 0;
}