#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int T;
    scanf("%d", &T);  
    for(int i = 0; i < T; i++) {

        int X, K;
        scanf("%d %d", &X, &K);

        if(X > K && K == 1){
            printf("1\n");
            continue;
        }

        int prod = 1;
        int n_terms = 0;
        int tX = X;
        bool is_ok = false;
        for(int j = 2; j*j <= tX; j++) {

            while(tX % j == 0) {
                // printf("j: %d tX: %d prod: %d n_terms: %d\n", j, tX, prod, n_terms);
                tX = tX / j;
                prod = prod * j;
                n_terms++;
                // printf("-> j: %d tX: %d prod: %d n_terms: %d\n", j, tX, prod, n_terms);
                if(n_terms == K - 1){
                    if(X % prod == 0 && X != prod){
                        is_ok = true;
                    }
                    break;
                }

            }

            if(n_terms == K - 1 & is_ok == true){
                break;
            }
        }

        if(n_terms == K - 1 & is_ok == true) {
            printf("1\n");
        } else {
            printf("0\n");
        }


    }
}