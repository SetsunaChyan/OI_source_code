    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <memory.h>
    #include <math.h>
    #include <assert.h>
    #include <queue>
    #include <map>
    #include <set>
    #include <string>
    #include <algorithm>
    #include <iostream>
    #include <functional>
    #include <unordered_map>
    #include <unordered_set>
    #include <list>
    #include <bitset>
     
    using namespace std;
    typedef pair<int, int> pii;
    typedef long long ll;
    #define Fi first
    #define Se second
    #define pb(x) push_back(x)
    #define szz(x) ((int)(x).size())
    #define rep(i, n) for(int i=0;i<n;i++)
    #define all(x) (x).begin(), (x).end()
    typedef tuple<int, int, int> t3;
    typedef pair<ll, ll> pll;
    typedef long double ldouble;
    typedef pair<double, double> pdd;
    typedef pair<pii, int> ppi;
     
    const int MOD = 1e9 + 7;
    int pw(int x, int y) {
    	int res = 1;
    	while(y) {
    		if(y & 1) res = (ll) res * x % MOD;
    		x = (ll) x * x % MOD;
    		y >>= 1;
    	}
    	return res;
    }
    int C[3030][3030];
     
    int main(){
    	for(int i=0;i<3030;i++) {
    		C[i][0] = 1;
    		for(int j=1;j<=i;j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    	}
    	int k, n; scanf("%d%d", &n, &k);
    	ll ans = 0;
    	for(int i=k;i>1;i--) {
    		if((k-i)&1) {
    			ans = (ans - C[k][i] * (ll) i % MOD * (ll) pw(i-1, n-1)) % MOD;
    			if(ans < 0) ans += MOD;
    		}
    		else {
    			ans = (ans + C[k][i] * (ll) i % MOD * pw(i-1, n-1)) % MOD;
    		}
    	}
    	printf("%lld\n", ans);
    	return 0;
    }