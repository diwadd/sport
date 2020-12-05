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
 
        int N, M;
        cin >> N >> M;

        vector<int> b_vec(N, 0);
        vector<int> l_vec(M, 0);

        for(int i = 0; i < N; i++) {
            cin >> b_vec[i];
        }

        for(int i = 0; i < M; i++) {
            cin >> l_vec[i];
        }

        set<int> bs(b_vec.begin(), b_vec.end());
        set<int> ls(l_vec.begin(), l_vec.end());

        int res = 0;
        for(auto it = bs.begin(); it != bs.end(); it++) {
            if(ls.find(*it) != ls.end()) {
                res++;
            }
        }

        cout << res << "\n";
    }


}