#include <bits/stdc++.h>
using namespace std;
const int N=105;
typedef unsigned long long ll;

int k,l;
char a[N],b[N];
ll fac[N];
set<int> pos[N];
int cha[26];

bool chk(){
    for(int t=0; t<l; t+=k){
        memset(cha,0,sizeof(cha));
        for(int i=0;i<k;++i){
            cha[a[i+t]-'a']--;
            cha[b[i+t]-'a']++;
        }
        for(int i=0;i<26;++i)
            if(cha[i]!=0) return 0;
    }
    return 1;
}

void gao()
{
    if(!chk()){
        puts("0");
        return;
    }
    for(int i=0;i<k;++i) pos[i].clear();
    for(int i=0;i<k;++i){
        for(int j=0;j<k;++j){
            if(a[i]==b[j]) pos[i].insert(j);
        }
    }
    for(int t=k; t<l; t+=k){
        set<int> tmp;
        for(int i=0;i<k;++i){
            tmp.clear();
            for(auto j:pos[i]){
                if(a[t+i]==b[t+j])
                    tmp.insert(j);
            }
            for(auto j:tmp){
                if(!pos[i].count(j)){
                    puts("0");
                    return;
                }
            }
            for(auto j:pos[i]){
                if(!tmp.count(j)){
                    puts("0");
                    return;
                }
            }
            set<int> tmp2;
            for(auto j:pos[i]){
                if(tmp.count(j)){
                    tmp2.insert(j);
                }
            }
            pos[i]=tmp2;
        }
    }
    for(int i=0;i<k;++i){
        for(int j=i+1;j<k;++j){
            if(pos[j].size()==0) continue;
            if(a[i]==a[j]) pos[j].clear(),pos[j].insert(0);
        }
    }
    ll ans=1;
    for(int i=0;i<k;++i)
        ans*=fac[pos[i].size()];
    printf("%llu\n",ans);
}

void pre(){
    fac[0]=0;
    fac[1]=1;
    int i=1;
    while(fac[i]*(i+1)<=((1LLU<<63)-1)){
        fac[i+1]=fac[i]*(i+1);
        i++;
    }
    //for(int j=0;j<=i;++j) cout<<fac[j]<<endl;
}

int main()
{
    pre();
    while(~scanf("%d",&k)){
        scanf("%s",a);
        scanf("%s",b);
        l=strlen(a);
        gao();
    }
    return 0;
}
