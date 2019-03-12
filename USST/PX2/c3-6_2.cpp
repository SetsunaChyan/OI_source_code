#include <cstdio>

int a[1005],s1[1005],s2[1005],n,ed1,ed2,ans;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        ed1=ed2=1;ans=s1[0]=s2[0]=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i++)
        {
            while(ed1&&a[i]>a[s1[ed1-1]]) ed1--;
            s1[ed1++]=i;
            if(ed1==1) ans=max(ans,i-s2[0]);
            while(ed2&&a[i]<a[s2[ed2-1]]) ed2--;
            s2[ed2++]=i;
            if(ed2==1){ed1==1;s1[0]=i;}
        }
        printf("%d\n",ans);
    }
    return 0;
}