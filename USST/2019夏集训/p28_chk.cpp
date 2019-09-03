    #include <bits/stdc++.h>
    using namespace std;

    char s[100005];
    const int MOD = 1e9 + 7;
    int main()
    {

        scanf("%s", s + 1);
        int L = strlen(s + 1), i = 1;
        int Sol = 1;
        while(i <= L){
            while(s[i] != 'a' && i <= L) ++i;
            int NR = 0;
            while(s[i] != 'b' && i <= L){
                if(s[i] == 'a') ++NR;
                ++i;
            }
            Sol = (Sol + 1LL * Sol * NR) % MOD;
        }

        --Sol;
        if(Sol < 0) Sol += MOD;
        printf("%d", Sol);

        return 0;
    }
