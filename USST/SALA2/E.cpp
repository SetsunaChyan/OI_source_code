#include <bits/stdc++.h>
using namespace std;

string s,tmp;
int cnt[10],ans,ts,k;

int f(int st,int y)
{
    for(int i=st;i>=0;i--)
        if(tmp[i]-'0'==y) return i;
    return -1;
}

void sp(int x,int y)
{
    char c=tmp[x];
    tmp[x]=tmp[y];
    tmp[y]=c;
}

int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
        cnt[s[i]-'0']++;
    if(s.size()==1)
    {
        printf("-1");
        return 0;
    }
    if(s.size()==2)
    {
        if(s==string("52")||s==string("57")) printf("1");
        else if(s==string("25")||s==string("50")||s==string("75")) printf("0");
        else printf("-1");
        return 0;
    }
    ans=0x3f3f3f3f;
    //00
    if(cnt[0]>=2)
    {
        tmp=s;ts=0;
        k=f(tmp.size()-1,0);
        for(int i=k;i<tmp.size()-1;i++)
            sp(i,i+1),ts++;
        k=f(tmp.size()-2,0);
        for(int i=k;i<tmp.size()-2;i++)
            sp(i,i+1),ts++;
        ans=min(ans,ts);
        //printf("00 %d\n",ans);
    }
    //25
    if(cnt[2]>=1&&cnt[5]>=1)
    {
        tmp=s;ts=0;
        k=f(tmp.size()-1,5);
        for(int i=k;i<tmp.size()-1;i++)
            sp(i,i+1),ts++;
        k=f(tmp.size()-2,2);
        for(int i=k;i<tmp.size()-2;i++)
            sp(i,i+1),ts++;
        for(int i=0;i<tmp.size()-2;i++)
            if(tmp[i]!='0') ans=min(ans,ts+i);
        //printf("25 %d\n",ans);
    }
    //50
    if(cnt[5]>=1&&cnt[0]>=1)
    {
        tmp=s;ts=0;
        k=f(tmp.size()-1,0);
        for(int i=k;i<tmp.size()-1;i++)
            sp(i,i+1),ts++;
        k=f(tmp.size()-2,5);
        for(int i=k;i<tmp.size()-2;i++)
            sp(i,i+1),ts++;
        for(int i=0;i<tmp.size()-2;i++)
            if(tmp[i]!='0') ans=min(ans,ts+i);
        //printf("50 %d\n",ans);
    }
    //75
    if(cnt[7]>=1&&cnt[5]>=1)
    {
        tmp=s;ts=0;
        k=f(tmp.size()-1,5);
        for(int i=k;i<tmp.size()-1;i++)
            sp(i,i+1),ts++;
        k=f(tmp.size()-2,7);
        for(int i=k;i<tmp.size()-2;i++)
            sp(i,i+1),ts++;
        for(int i=0;i<tmp.size()-2;i++)
            if(tmp[i]!='0') ans=min(ans,ts+i);
        //printf("75 %d\n",ans);
    }
    if(ans==0x3f3f3f3f) printf("-1");
    else printf("%d",ans);
    return 0;
}
