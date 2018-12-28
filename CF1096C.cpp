#include <cstdio>

const double eps=1e-5;
int n,ans[200];

inline double abs(double x){return x<0?-x:x;}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<180;i++)
    {
        int flag=0;
        for(int k=3;k<=360;k++)
        {
            double g=i/(180.0/k);
            //printf("%lf\n",g);
            if(abs(g-int(g))<eps&&g<=k-2)
            {
                ans[i]=k;
                flag=1;
                break;
            }
        }
        if(!flag) ans[i]=-1;
    }
    while(n--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}