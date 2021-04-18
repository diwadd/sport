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
            cout << vec[i];
        else
            cout << vec[i] << " ";
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

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N, Q;
        cin >> N >> Q;

        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }

        const int MAX_BITS = 33;
        vector<int> bits(MAX_BITS, 0);

        bitset<MAX_BITS> res(0);
        for(int i = 0; i < N; i++) {
            bitset<MAX_BITS> b(a_vec[i]);

            for(int j = 0; j < b.size(); j++) {
                if(b[j] == 1) {
                    bits[j] += 1;
                }
            }

            res |= b;
        }

        cout << res.to_ullong() << "\n";


        for(int i = 0; i < Q; i++) {
            int X, V;
            cin >> X >> V;

            X = X - 1;
            bitset<MAX_BITS> b1(a_vec[X]);
            for(int j = 0; j < b1.size(); j++) {
                if(b1[j] == 1){
                    bits[j] -= 1;
                }
            }

            a_vec[X] = V;
            bitset<MAX_BITS> b2(V);
            for(int j = 0; j < b2.size(); j++) {
                if(b2[j] == 1) {
                    bits[j] += 1;
                }
            }

            bitset<MAX_BITS> new_res(0);
            for(int j = 0; j < bits.size(); j++) {
                if(bits[j] > 0)
                    new_res[j] = 1;
            }

            // print_vector(bits);
            cout << new_res.to_ullong() << "\n";
        }
    }
}