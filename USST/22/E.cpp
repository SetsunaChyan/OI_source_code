#include <cstdio>

int n,sq[200005],s[100],p[100];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;(long long)i*i<=n;i++)
        sq[i]=i*i;
    int k=0;
    i--;
    while(n)
    {
        s[k]=n%10;
        n/=10;
        k++;
    }    
    for(;i>=1;i--)
    {
        for(int j=0;j<k;j++)
            p[j]=s[j];
        int kk=0,fflag=1,lst=0;
        while(sq[i])
        {
            int tmp=sq[i]%10,flag=0;
            for(int j=lst;j<k;j++)
                if(tmp==p[j])
                {
                    p[j]=-1;
                    lst=j;
                    flag=1;
                    break;
                }
            if(!flag)
            {
                fflag=0;
                break;
            }
            sq[i]/=10;
            kk++;
        }
        if(fflag)
        {
            printf("%d",k-kk);
            return 0;
        }
    }
    printf("-1");
    return 0;
}