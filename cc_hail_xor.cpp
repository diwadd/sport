#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void left_just(string &s, int n, char c = ' ') {
    while(s.length() < n) {
        s = c + s;
    }
}

template<typename T> void print_vector(vector<T> &vec) {

    int n = vec.size();
    for(int i = 0; i < n; i++) {
        if(i == n - 1)
            cout << vec[i].to_ulong();
        else
            cout << vec[i].to_ulong() << " ";
    }
    cout << "\n";
}

template<typename T> void print_matrix(vector<vector<T>> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        print_vector(mat[i]);
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr int MAX_NUM_BITS = 34;

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N, X;
        cin >> N >> X;

        vector<bitset<MAX_NUM_BITS>> a_vec(N, bitset<MAX_NUM_BITS>());
        for(int n = 0; n < N; n++) {

            int a;
            cin >> a;
            a_vec[n] = bitset<MAX_NUM_BITS>(a);
        }

        int n_moves = 0;
        for(int i = 0; i < N-1; i++) {
            if(n_moves >= X) {
                break;
            }

            for(int j = MAX_NUM_BITS-1; j >= 0; j--) {

                if(n_moves >= X) {
                    break;
                }

                if(a_vec[i][j] == 0)
                    continue;

                bool found = false;
                int found_k = -1;
                for(int k = i + 1; k < N; k++) {
                    if(a_vec[k][j] == 1) {
                        found = true;
                        found_k = k;
                        break;
                    }
                }

                if(found == true) {
                    a_vec[i] = a_vec[i] ^ bitset<MAX_NUM_BITS>(1 << j);
                    a_vec[found_k] = a_vec[found_k] ^ bitset<MAX_NUM_BITS>(1 << j);
                    n_moves++;
                } else {
                    if(i != N - 1) {
                        a_vec[i] = a_vec[i] ^ bitset<MAX_NUM_BITS>(1 << j);
                        a_vec[N-1] = a_vec[N-1] ^ bitset<MAX_NUM_BITS>(1 << j);
                        n_moves++;
                    }
                }
            }
        }


        if(N == 2 && (X - n_moves) % 2 != 0) {
            a_vec[N-1] = a_vec[N-1] ^ bitset<MAX_NUM_BITS>(1);
            a_vec[N-2] = a_vec[N-2] ^ bitset<MAX_NUM_BITS>(1);
        }

        print_vector(a_vec);
    }
}