    #include <bits/stdc++.h>
    using namespace std;

    int a[100005];
    int flag=0;

    int main()
    {
        long long sum=0;
        int n,cnt=0,cnt1=0;
        scanf("%d",&n);
        a[0]=-1;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n+1);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[i-1]) cnt++;
            if((a[i]-a[i-1])%2==0) cnt1++;
            if(a[i]==a[i-1]&&(a[i]-a[i-2])%2==1&&a[i-2]!=-1)
            {
                printf("cslnb");
                return 0;
            }
        }
        if(cnt>=2)
        {
            printf("cslnb");
            return 0;
        }
        if(cnt1&1)
            printf("sjfnb");
        else
            printf("cslnb");
        return 0;
    }
