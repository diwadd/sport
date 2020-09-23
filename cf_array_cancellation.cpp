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
        lli N;
        cin >> N;

        vector<lli> a_vec(N, 0);
        for(int n = 0; n < N; n++)
            cin >> a_vec[n];

        vector<lli> mss(N, 0);
        mss[N-1] = a_vec[N-1];
        for(int i = N - 2 ; i >= 0; i--) {
            mss[i] = a_vec[i] + mss[i+1];
        }

        // print_vector(mss);

        lli m = numeric_limits<lli>::min();
        for(int i = 0; i < N; i++) {
            if(m < mss[i]) {m = mss[i];}
        }   

        cout << m << "\n";
    }

}