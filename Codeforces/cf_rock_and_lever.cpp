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
 
        int N;
        cin >> N;

        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }

        const int MAX_ELE = 32;
        vector<ulli> freq(MAX_ELE, 0);

        for(int i = 0; i < N; i++) {
            int nb = (int)log2(a_vec[i]);
            freq[nb]++;
        }

        // print_vector(freq);

        ulli res = 0;
        for(int i = 0; i < MAX_ELE; i++) {
            if(freq[i] > 1) {
                res = res + (freq[i] * (freq[i] - 1)) / 2;
            }
        }

        cout << res << "\n";

    }
}