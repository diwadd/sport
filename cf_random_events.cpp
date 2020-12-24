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

        vector<int> a_vec(N+1, 0);
        for(int i = 1; i <= N; i++) {
            cin >> a_vec[i];
        }

        int last = 1;
        for(int i = N; i >= 1; i--) {
            if(a_vec[i] == i) {
                continue;
            } else {
                last = i;
                break;
            }
        }

        // print_vector(a_vec);
        // cout << "Last: " << last << endl;

        vector<pair<int, double>> experiment(M, pair<int, double>(0, 0.0));
        for(int i = 0; i < M; i++) {
            int r;
            double p;
            cin >> r >> p;
            experiment[i] = make_pair(r, p);
        }

        if(last == 1) {
            cout << "1.0\n";
            continue;
        }

        double res = 1.0;
        for(int i = 0; i < M; i++) {
            int r = experiment[i].first;
            double p = experiment[i].second;

            if(r >= last) {
                // cout << "multi: " << 1-p << "\n";
                res = res * (1.0 - p);
            }
        }


        cout << (1 - res) << "\n";


    }


}