#include <cstdio>
#include <cstring>

const char tp[3]={'R','G','B'};
const char tp1[3]={'R','B','G'};
char s[200005];
int n,cnt[3],cnt1[3];

inline int min(int a,int b){return a<b?a:b;}

int main()
{
    cnt[0]=cnt[1]=cnt[2]=0;
    cnt1[0]=cnt1[1]=cnt1[2]=0;
    scanf("%d %s",&n,s);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            if(s[i]!=tp[(i+j)%3]) cnt[j]++;
        for(int j=0;j<3;j++)
            if(s[i]!=tp1[(i+j)%3]) cnt1[j]++;
    }
    int a=min(cnt[1],min(cnt[0],cnt[2]));
    int b=min(cnt1[1],min(cnt1[0],cnt1[2]));
    if(a<=b)
    {
        printf("%d\n",a);
        if(cnt[0]<=cnt[1]&&cnt[0]<=cnt[2])
            for(int i=0;i<n;i++)
                printf("%c",tp[i%3]);
        else if(cnt[1]<=cnt[0]&&cnt[1]<=cnt[2])
            for(int i=0;i<n;i++)
                printf("%c",tp[(i+1)%3]);
        else
            for(int i=0;i<n;i++)
                printf("%c",tp[(i+2)%3]);
    }
    else
    {
        printf("%d\n",b);
        if(cnt1[0]<=cnt1[1]&&cnt1[0]<=cnt1[2])
            for(int i=0;i<n;i++)
                printf("%c",tp1[i%3]);
        else if(cnt1[1]<=cnt1[0]&&cnt1[1]<=cnt1[2])
            for(int i=0;i<n;i++)
                printf("%c",tp1[(i+1)%3]);
        else
            for(int i=0;i<n;i++)
                printf("%c",tp1[(i+2)%3]);
    }
    return 0;
}