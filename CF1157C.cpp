#include <bits/stdc++.h>
using namespace std;

int n,a[200005],cnt=0,l,r,lm,rm,last=-1;
char s[200005];

void addl(int i)
{
    cnt++;
    last=a[l++];
    s[i]='L';
}

void addr(int i)
{
    cnt++;
    last=a[r--];
    s[i]='R';
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    l=lm=0,r=rm=n-1;
    for(int i=0;i<n;i++)
    {
        if(l<lm)
        {
            if(a[l]<=last) break;
            addl(i);
        }
        else if(r>rm)
        {
            if(a[r]<=last) break;
            addr(i);
        }
        else
        {
            if(a[r]<a[l])
            {
                if(a[r]>last)
                {
                    addr(i);
                    continue;
                }
            }
            if(a[l]<a[r])
            {
                if(a[l]>last)
                {
                    addl(i);
                    continue;
                }
            }
            if(a[l]<=last&&a[r]>last)
            {
                addr(i);
                continue;
            }
            if(a[r]<=last&&a[l]>last)
            {
                addl(i);
                continue;
            }
            if(a[l]==a[r]&&a[l]>last)
            {
                lm=l,rm=r;
                while(lm<rm&&a[lm]==a[rm]) lm++,rm--;
                //if(min(a[lm],a[rm])<=last) break;
                if(lm>=rm) {lm=r;rm=r;addl(i);}
                else if(a[lm]<a[rm]) {lm++;rm=r;addl(i);}
                else {rm--;lm=l;addr(i);}
                continue;
                //printf("%d %d %d %d\n",lm,rm,l,r);
            }
            break;
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++) printf("%c",s[i]);
    return 0;
}