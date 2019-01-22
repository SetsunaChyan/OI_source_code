#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=3e5+50;
char s1[MAXN],s2[MAXN],ans[MAXN];
int n,s1l,s1r,s2l,s2r,sl,sr;

int main()
{
    scanf("%d%s%s",&n,s1,s2);
    sort(s1,s1+n/2);
    sort(s2,s2+n/2);
    s1l=s2l=sl=0,s1r=s2r=n/2-1,sr=n-1;
    ans[n]='\0';
    for(int i=0;i<n;i++)
    {
        if(!(i&1))
            if(s1[s1l]>=s2[s2r])
                ans[sr]=s1[s1r],s1r--,sr--;
            else
                ans[sl]=s1[s1l],s1l++,sl++;
        else
            if(s2[s2r]<=s1[s1l])
                ans[sr]=s2[s2l],s2l++,sr--;
            else
                ans[sl]=s2[s2r],s2r--,sl++;
        //printf("%s\n",ans);
    }
    printf("%s",ans);
    return 0;
}