#include <cstdio>

int _,n,a[1005],ans;

int main()
{
    freopen("data2.out","w",stdout);
    freopen("data.in","r",stdin);
    scanf("%d",&_);
    while(_--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
        {
            int f=0;
            for(int j=0;j<n-i;j++)
            {
                int flag=1;
                for(int k=j+1;k<=i+j;k++)
                    if(a[k]<a[j]||a[k]>a[i+j])
                    {
                        flag=0;
                        break;
                    }
                if(flag)
                {
                    f=1;
                    break;
                }
            }
            if(f) ans=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}