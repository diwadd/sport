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

    int n, q;
    cin >> n >> q;
 
    vector<int> a_vec(n, 0);
    int n_ones = 0;
    int n_zeros = 0;
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a_vec[i] = ai;

        if(ai == 1)
            n_ones++;
        else
            n_zeros++;
    }

    for(int i = 0; i < q; i++) {

        int t, xk;
        cin >> t >> xk;

        if(t == 1) {

            xk--;
            if(a_vec[xk] == 0) {
                a_vec[xk] = 1;
                n_zeros--;
                n_ones++;
            } else if (a_vec[xk] == 1) {
                a_vec[xk] = 0;
                n_zeros++;
                n_ones--;
            }

        } else if (t == 2) {

            if(xk <= n_ones) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }

        }
    }


}