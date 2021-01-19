#include <bits/stdc++.h> 
// #include <numeric>

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

template<typename T> void print_vector(vector<T> &vec) {

    int n = vec.size();
    for(int i = 0; i < n; i++) {
            cout << vec[i];
    }
    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t_ = 0; t_ < T; t_++) {
 
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> s_vec(n, 0);
        for(int i = 0; i < n; i++) {
            if(s[i] == '1')
                s_vec[i] = 1;
        }

        vector<int> a_vec(n, 0);
        a_vec[0] = 1;
        int c;
        if(s_vec[0] == 0)
            c = 1;
        else
            c = 2;

        for(int i = 1; i < n; i++) {
            if(c == 1 && s_vec[i] == 0) {
                a_vec[i] = 0;
                c = 0;
            } else if (c == 1 && s_vec[i] == 1) {
                a_vec[i] = 1;
                c = 2;
            } else if (c == 2 && s_vec[i] == 0) {
                a_vec[i] = 1;
                c = 1;
            } else if (c == 2 && s_vec[i] == 1) {
                a_vec[i] = 0;
                c = 1;
            } else if (c == 0 && s_vec[i] == 0) {
                a_vec[i] = 1;
                c = 1;
            } else if (c == 0 && s_vec[i] == 1) {
                a_vec[i] = 1;
                c = 2;
            }
        }
        print_vector(a_vec);

    }
}