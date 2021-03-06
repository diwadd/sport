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

        int N, k;
        cin >> N >> k;
        vector<int> a_vec(N, 0);
        int min_val = numeric_limits<int>::max();
        int index = 0;
        for(int n = 0; n < N; n++) {
            cin >> a_vec[n];
            if(min_val > a_vec[n]) {
                min_val = a_vec[n];
                index = n;
            }
        }

        int res = 0;

        for(int n = 0; n < N; n++) {
            if(n != index)
                res = res + max(k - a_vec[n], 0) / min_val;
        }    

        cout << res << "\n";
    }

}