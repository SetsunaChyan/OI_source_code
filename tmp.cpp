#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

const int MAXN = 1e6 + 10;
const int MAX = 1e5;
int prime[MAX], tag[MAX], vis[MAXN], tot;

void get_prime(void){
    for(int i = 2; i < MAX; i++){
        if(!tag[i]){
            prime[tot++] = i;
            for(int j = 2; j * i < MAX; j++){
                tag[j * i] = 1;
            }
        }
    }
}

ll Max(ll a, ll b){
    return a > b ? a : b;
}

int main(void){
    get_prime();
    ll l, r;
    while(~scanf("%lld%lld", &l, &r)){
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < tot; i++){
            ll a = (l + prime[i] - 1) / prime[i];
            ll b = r / prime[i];
            for(int j = Max(2, a); j <= b; j++){ // 筛[l, r]内的合数
                vis[prime[i] * j - l] = 1; //减个l方便标记,输出答案时加回去即可
            }
        }
        if(l == 1) vis[0] = 1; // 注意这个1并不是素数
        ll cnt = -1, sol1 = MAXN, sol2 = 0, x1, y1, x2, y2;
        for(int i = 0; i <= r - l; i++){
            if(vis[i] == 0){
                if(cnt != -1){
                    if(sol1 > i - cnt){
                        x1 = cnt;
                        y1 = i;
                        sol1 = i - cnt;
                    }
                    if(sol2 < i - cnt){
                        x2 = cnt;
                        y2 = i;
                        sol2 = i - cnt;
                    }
                }
                cnt = i;
            }
        }
        if(sol2 == 0) puts("There are no adjacent primes.");
        else printf("%lld,%lld are closest, %lld,%lld are most distant.\n", x1 + l, y1 + l, x2 + l, y2 + l);
    }
    return 0;
}
