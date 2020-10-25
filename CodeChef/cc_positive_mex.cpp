#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;

template<typename T> void print_vector(vector<T> &v, int n) {

    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

}

int main() {

    const ulli MOD7 = 1000000000+7;
    const ulli MOD9 = 998244353;
    const ulli MAX_N = 100000;
    const ulli N_OFFSET = 10;

    vector<ulli> powers_of_two(MAX_N + N_OFFSET, 0);
    powers_of_two[0] = 1;

    for(int i = 1; i < powers_of_two.size(); i++) {
        powers_of_two[i] = (powers_of_two[i-1]*2) % MOD9;

    }

    // // // printf_vector(powers_of_two, 100);

    int T;
    scanf("%d", &T);    
    for(int i = 0; i < T; i++) {

        ulli N;
        scanf("%llu", &N);

        vector<ulli> a_vec(N, 0);

        vector<ulli> freq(MAX_N + N_OFFSET, 0);
        vector<ulli> more_than(MAX_N + N_OFFSET, 0);

        for(int j = 0; j < N; j++) {
            scanf("%llu", &a_vec[j]);

            if( a_vec[j] <= MAX_N ) {
                ++freq[a_vec[j]];
            } else {
                ++freq[MAX_N + 1];
            }

        }

        sort(a_vec.begin(), a_vec.end());

        int max_m = 1;
        int j_marked = 0;
        for(int j = 0; j < N; j++) {
            int a = a_vec[j];

            if( a == max_m ) {
                continue;
            }

            if(a == max_m + 1) {
                more_than[max_m] = N - j;
                max_m = max_m + 1;
                j_marked = j;
                continue;
            }

            if(a > max_m + 1) {
                more_than[max_m] = N - j;
                max_m = max_m + 1;
                more_than[max_m] = N - j;
                break;
            }

        }

        max_m = max_m + 1;

        // // printf("max_m: %d\n", max_m);

        // // print_vector(freq, N + 1);
        // // print_vector(more_than, N+1);

        ulli res = 0;
        ulli x_factor = 1;
        int x = 1;

        int gm = more_than[1];
        ulli p1 = ( (1 % MOD9) * (powers_of_two[gm] % MOD9) ) % MOD9;

        res = ((res % MOD9) + (p1 % MOD9)) % MOD9;

        for(int m = 2; m <= max_m; m++) {

            gm = more_than[m];
            p1 = ( (m % MOD9) * (powers_of_two[gm] % MOD9) ) % MOD9;

            // printf("m: %d gm: %d p1: %llu\n", m, gm, p1);



            int fx = freq[x];
            // printf("x: %d fx: %d x_factor: %llu\n", x, fx, x_factor);
            x_factor = ((x_factor % MOD9) * ((powers_of_two[fx] - 1) % MOD9)) % MOD9;
            ++x;

            // printf("x_factor: %llu\n", x_factor);

            res = ((res % MOD9) + (p1 * ( x_factor % MOD9 )) % MOD9) % MOD9;
            // printf("res: %llu\n", res);
        }

        printf("%llu\n", res);
    }
}