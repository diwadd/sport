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
 
        lli n, u, v;
        cin >> n >> u >> v;

        vector<lli> a_vec(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> a_vec[i];
        }

        lli cost = numeric_limits<lli>::max();
        for(int i = 0; i < n-1; i++) {
            lli j = a_vec[i];
            lli x = a_vec[i+1];
            lli delta = abs(j-x);

            // cout << "j: " << j << " x: " << x << " delta: " << delta << "\n";
            if(delta > 1) {
                cost = 0;
                break;
            } else if(delta == 0) {
                cost = min(cost, min(u+v, v+v));
            } else if(delta == 1) {
                cost = min(cost, min(u, v));
            }
        }

        cout << cost << "\n";
    }
}