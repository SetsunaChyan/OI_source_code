#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
int cnt,len,ans,p[N*2];
char s[N],ss[N*2];

void init() //将每两个字符中插入一个字符
{
    len=strlen(s),cnt=1;
    ss[0]='!',ss[cnt]='#';
    for(int i=0;i<len;i++)
        ss[++cnt]=s[i],ss[++cnt]='#';
}

void manacher()
{
    int pos=0,mx=0;
    for(int i=1;i<=cnt;i++)
    {
        if(i<mx) p[i]=min(p[pos*2-i],mx-i);
        else p[i]=1;
        while(ss[i+p[i]]==ss[i-p[i]]) p[i]++;
        if(mx<i+p[i]) mx=i+p[i],pos=i;
        ans=max(ans,p[i]-1);
    }
}

int main()
{
    scanf("%s",s);
    init();
    manacher();
    printf("%d\n",ans);
    return 0;
}
