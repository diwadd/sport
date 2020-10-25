#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;

int main() {


    int T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++) {
        int N, K;
        scanf("%d %d", &N, &K);

        int lost_rev = 0;
        for(int n = 0; n < N; n++) {
            int p;
            scanf("%d", &p);

            if(p > K) {
                lost_rev += p - K;
            }


        }

        printf("%d\n", lost_rev);

    }

}