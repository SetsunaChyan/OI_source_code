#include<cstdio>
#include<cstring>
#include<queue>
#define int long long
using namespace std;

int ch[111][4],fail[111],tn;
bool flag[111];

int idx[128];
void insert(char *s){
    int x=0;
    for(int i=0; s[i]; ++i){
        int y=idx[s[i]];
        if(ch[x][y]==0) ch[x][y]=++tn;
        x=ch[x][y];
    }
    flag[x]=1;
}
void init(){
    memset(fail,0,sizeof(fail));
    queue<int> que;
    for(int i=0; i<4; ++i){
        if(ch[0][i]) que.push(ch[0][i]);
    }
    while(!que.empty()){
        int now=que.front(); que.pop();
        for(int i=0; i<4; ++i){
            if(ch[now][i]) que.push(ch[now][i]),fail[ch[now][i]]=ch[fail[now]][i];
            else ch[now][i]=ch[fail[now]][i];
            flag[ch[now][i]]|=flag[ch[fail[now]][i]];
        }
    }
}
struct Mat{
    long long mat[111][111];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
};
Mat operator*(const Mat &m1,const Mat &m2){
    Mat m;
    for(int i=0; i<=tn; ++i){
        for(int j=0; j<=tn; ++j){
            for(int k=0; k<=tn; ++k){
                m.mat[i][j]+=m1.mat[i][k]*m2.mat[k][j];
                m.mat[i][j]%=998244353;
            }
        }
    }
    return m;
}
signed main(){
    idx['A']=0; idx['C']=1; idx['T']=2; idx['G']=3;
    char str[11];
    int m,n;
    while(~scanf("%lld%lld",&m,&n)){
        tn=0;
        memset(flag,0,sizeof(flag));
        memset(ch,0,sizeof(ch));
        while(m--){
            scanf("%s",str);
            insert(str);
        }
        init();
        Mat e,x;
        for(int i=0; i<=tn; ++i) e.mat[i][i]=1;
        for(int i=0; i<=tn; ++i){
            if(flag[i]) continue;
            for(int j=0; j<4; ++j){
                if(flag[ch[i][j]]) continue;
                ++x.mat[i][ch[i][j]];
            }
        }
        while(n){
            if(n&1) e=e*x;
            x=x*x;
            n>>=1;
        }
        long long res=0;
        for(int i=0; i<=tn; ++i){
            res+=e.mat[0][i];
            res%=998244353;
        }
        printf("%lld\n",res);
    }
    return 0;
}
