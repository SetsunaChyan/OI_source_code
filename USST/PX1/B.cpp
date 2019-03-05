#include <cstdio>
#include <memory.h>

int l,r,a[6],cnt=0,sum;

bool is_prime(int x)
{
    if(x<2) return false;
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}

int main()
{
    memset(a,0,sizeof(a));
    scanf("%d%d",&l,&r);
    for(int i=0;i<81*9;i++)
    {
        sum=0;
        for(int j=0;j<6;j++)
            sum+=a[j];
        if(sum>=l&&sum<=r||is_prime(sum))
            cnt++;
        a[0]++;
        for(int j=0;j<5;j++)
            if(a[j]==3) {a[j]=0;a[j+1]++;}
    }
    printf("%d",cnt);
    return 0;
}