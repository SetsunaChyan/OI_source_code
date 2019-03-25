#include <cstdio>

int l,r,ans;

inline int min(int a,int b){return a<b?a:b;}

bool check(int l,int r,int x,int y)
{
    if(l==x&&r==y) return true;
    if(l>x||r<y) return false;
    int mid=(l+r)/2;
    if(x<=mid) return check(l,mid,x,y);
    else return check(mid+1,r,x,y);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        ans=0x3f3f3f3f;
        scanf("%d%d",&l,&r);
        if(check(1,r,l,r)) ans=r;
        for(int k=0;k<=l;k+=r-l+1)
        {
            if(ans<=2*k-1) break;
            if(check(1,2*k,l,r)) ans=min(ans,2*k);
            if(check(1,2*k-1,l,r)) ans=min(ans,2*k-1);
        }
        if(ans==0x3f3f3f3f)
            printf("-1\n");
        else 
            printf("%d\n",ans);
    }
    return 0;
}