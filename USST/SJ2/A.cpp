#include <cstdio>

bool is_prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}

int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=n-1;i;i--)
        if(is_prime(i))
        {
            printf("%6d",i);
            cnt++;
            if(cnt==10) break;
        }
    return 0;
}