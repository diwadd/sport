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

    lli N;
    cin >> N;

    vector<lli> a_vec(N, 0);
    for(int n = 0; n < N; n++) {
        cin >> a_vec[n];
    }

    set<lli> a_set;
    a_set.insert(0);
    lli p = 0;
    lli res = 0;
    for(int n = 0; n < N; n++){
        p = p + a_vec[n];
        if(a_set.find(p) != a_set.end()) {
            res++;
            a_set.clear();
            a_set.insert(0);
            p = a_vec[n];
        }
        a_set.insert(p);
    }

    cout << res << "\n";

}