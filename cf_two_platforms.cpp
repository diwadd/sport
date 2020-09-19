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
 
        int N, K;
        cin >> N >> K;

        vector<int> x_vec(N, 0);
        vector<int> y_vec(N, 0);

        for(int n = 0; n < N; n++)
            cin >> x_vec[n];

        for(int n = 0; n < N; n++)
            cin >> y_vec[n];

        sort(x_vec.begin(), x_vec.end());
        // cout << "x_vec: "; print_vector(x_vec);

        vector<int> l_vec(N, 0);
        vector<int> r_vec(N, 0);

        int l = 0;
        int r = N-1;

        for(int n = N-1; n >= 0; n--) {
            while(abs(x_vec[n] - x_vec[r]) > K ) {
                if(r == 0)
                    break;
                r = max(r-1, 0);
            }
            r_vec[n] = r - n + 1;
        }

        for(int n = 0; n < N; n++) {
            // cout << "abs(x_vec[" << n << "] - x_vec[" << l << "]): " << abs(x_vec[n] - x_vec[l]) << "\n";
            while(abs(x_vec[n] - x_vec[l]) > K) {
                if(l == N-1)
                    break;
                l = min(l+1, N-1);
            }
            l_vec[n] = n - l + 1;
        }
    
        // cout << "l_vec: "; print_vector(l_vec);
        // cout << "r_vec: "; print_vector(r_vec);

        vector<int> l_sma(N, 0);
        vector<int> r_sma(N, 0);
        l_sma[0] = l_vec[0];     
        r_sma[N-1] = r_vec[N-1];  

        for(int n = 1; n < N; n++) {
            l_sma[n] = max(l_sma[n-1], l_vec[n]);
        }

        for(int n = N-2; n >= 0; n--) {
            r_sma[n] = max(r_sma[n+1], r_vec[n]);
        }

        // cout << "l_sma: "; print_vector(l_sma);
        // cout << "r_sma: "; print_vector(r_sma);

        int res = 1;
        for(int i = 0; i < N - 1; i++) {
            res = max(res, r_sma[i+1] + l_sma[i]);
        }

        cout << res << "\n";
    }
}