#include <cstdio>

int n,e=0;
long long ans;
struct node
{
    int num,t;
}s[500000],temp;


int main()
{
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp.num);
        temp.t=1;
        while(e>0&&s[e-1].num<=temp.num)
        {
            if(s[e-1].num==temp.num) temp.t=s[e-1].t+1;
            ans+=s[e-1].t;
            e--;
        }
        if(e!=0) ans++;
        s[e++]=temp;
    }
    printf("%lld\n",ans);
    return 0;
}
