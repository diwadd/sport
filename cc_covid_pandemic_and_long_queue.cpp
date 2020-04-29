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

        int N;
        scanf("%d", &N);
        int p1 = -1;
        bool is_ok = true;
        for(int j = 0; j < N; j++) {
            int a;
            scanf("%d", &a);

            if(a == 1 && p1 == -1){
                p1 = j;
                continue;
            }
            if(a == 1){
                // printf("d = %d\n", j - p1);
                if(j - p1 < 6){
                    is_ok = false;
                }
                p1 = j;
            }

        }

        if(is_ok == true){
            printf("YES\n");
        } else {
            printf("NO\n"); 
        }


    }
}