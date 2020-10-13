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

        int N, X, p, k;
        cin >> N >> X >> p >> k;

        p = p - 1;
        k = k - 1;
        vector<int> a_vec(N, 0);
        for(int n = 0; n < N; n++) {
            cin >> a_vec[n];
        }

        sort(a_vec.begin(), a_vec.end());

        int res = 0;
        if(p == k) {
            int index = -1;
            if(a_vec[k] < X) {
                for(int i = k; i < N; i++) {
                    if(a_vec[i] < X) {
                        index = i;
                    }
                }
                res = index - k + 1;

            } else if (a_vec[k] > X) {
                for(int i = k; i >= 0; i--) {
                    if(a_vec[i] > X) {
                        index = i;
                    }
                }
                if(index == -1)
                    index = 0;
                res = k - index + 1;
            }
            cout << res << "\n";
        } else if (p < k) {
            if(a_vec[p] < X) {
                cout << "-1\n";
                continue;
            } else if(a_vec[p] > X) {
                int index = -1;
                for(int i = p; i >= 0; i--) {
                    if(a_vec[i] > X) {
                        index = i;
                    }
                }
                res = p - index + 1;
            }
            cout << res << "\n";
        } else if (p > k) {
            if(a_vec[p] > X) {
                cout << "-1\n";
                continue;
            } else if(a_vec[p] < X) {
                int index = -1;
                for(int i = p; i < N; i++) {
                    if(a_vec[i] < X) {
                        index = i;
                    }
                }
                res = index - p + 1;
            }
            cout << res << "\n";
        }

    }

}