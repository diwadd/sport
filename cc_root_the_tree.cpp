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

        vector<pair<int, int>> edges(N-1, pair<int,int>(0,0));
        for(int i = 0; i < N-1; i++) {
            int u, v;
            cin >> u >> v;

            edges[i] = make_pair(u, v);
        }

        vector<int> in_degree_count(N+1, 0);
        for(int i = 0; i < N - 1; i++) {
            // Edge is directed from u to v (u -> v).
            int u = edges[i].first;
            int v = edges[i].second;

            in_degree_count[v]++;
        }

        // print_vector(in_degree_count);

        int res = 0;
        for(int i = 0; i < N+1; i++) {
            if(in_degree_count[i] >= 2) {
                res = res + (in_degree_count[i] - 1);
            }
        }

        cout << res << "\n";

    }


}