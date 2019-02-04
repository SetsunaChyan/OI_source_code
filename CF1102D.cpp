#include <cstdio>

int s[300005],n,cnt[3],k;

int main()
{
    cnt[0]=cnt[1]=cnt[2]=0;
    scanf("%d",&n);
    k=n/3;
    for(int i=0;i<n;i++)
    {
        scanf("%1d",&s[i]);
        cnt[s[i]]++;
    }
    for(int i=0;i<n;i++)
        if(cnt[s[i]]>k&&cnt[0]<k)
        {
            cnt[0]++;
            cnt[s[i]]--;
            s[i]=0;
        }
    for(int i=n-1;i>=0;i--)
        if(cnt[s[i]]>k&&cnt[2]<k)
        {
            cnt[2]++;
            cnt[s[i]]--;
            s[i]=2;
        }
    for(int i=0;i<n;i++)
        if(s[i]==2&&cnt[2]>k&&cnt[1]<k)
        {
            cnt[1]++;
            cnt[2]--;
            s[i]=1;
        }
    for(int i=n-1;i>=0;i--)
        if(s[i]==0&&cnt[0]>k&&cnt[1]<k)
        {
            cnt[1]++;
            cnt[0]--;
            s[i]=1;
        }
    for(int i=0;i<n;i++)
        printf("%d",s[i]);
    return 0;
}