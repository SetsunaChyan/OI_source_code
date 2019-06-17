#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
double p;
int c[25][25];
double dp[25];
int main() {
    scanf("%d%lf", &n, &p);
    c[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            dp[i] += dp[j] * c[i - 1][j - 1] * pow((1 - p), j * (i - j));
        }
        dp[i] = 1.0 - dp[i];
    }
    printf("%.3f\n", dp[n]);
    return 0;
}
