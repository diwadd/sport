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
 

        string s;
        cin >> s;

        int N = s.size();

        vector<char> c_vec;
        c_vec.reserve(N);

        for(int i = 0; i < N; i++) {
            // print_vector(c_vec);
            if(s[i] == 'A') {
                c_vec.push_back(s[i]);
            }

            if(s[i] == 'B') {
                if(c_vec.back() == 'A') {
                    c_vec.pop_back();
                } else if (c_vec.back() == 'B') {
                    c_vec.pop_back();
                } else if (c_vec.size() == 0) {
                    c_vec.push_back(s[i]);
                }
            }
        }

        cout << c_vec.size() << "\n";

    }
}