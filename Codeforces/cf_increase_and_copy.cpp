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

        if(N == 1){
            cout << "0\n";
            continue;
        }

        lli mid = lli(sqrt(N));
        lli b = 10;

        lli res = numeric_limits<lli>::max();
        for(lli i = max(mid - b, lli(1)); i <= mid + b; i++) {
            res = min(res, i - 1 + lli(floor((N - 1)/i)) );
        }
        cout << res << "\n";

    }
}