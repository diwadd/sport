#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


int main() {

    const unsigned long long int MOD7 = 1000000000+7;

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int T;
    scanf("%d", &T);   
    for(int i = 0; i < T; i++) {

        int N;
        scanf("%d", &N);

        vector<int> vec(N, 0);
        for(int j = 0; j < N; j++) {
            int p;
            scanf("%d", &p);
            vec[j] = p;
        }

        sort(vec.rbegin(), vec.rend());

        for(int j = 1; j < N; j++) {

            vec[j]= max(0, vec[j] - j);
            // cout << "vec[j]: " << vec[j] << endl;
        }

        unsigned long long int sum = 0;
        for(int j = 0; j < N; j++) {
            sum = (sum % MOD7 + (unsigned long long int)vec[j] % MOD7);
        }

        // for(auto v : vec) {
        //     cout << v << " ";
        // }
        // cout << endl;

        printf("%llu\n", sum % MOD7);
    }
}