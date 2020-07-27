#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

void left_just(string &s, int n, char c = ' ') {
    while(s.length() < n) {
        s = c + s;
    }
}

template<typename T> void print_vector(vector<T> &vec) {

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
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

    for(int t = 1; t <= T; t++) {

        int N, K, P;
        cin >> N >> K >> P;
        
        vector<vector<int>> stacks_of_plates(N+1, vector<int>(K+1, 0));

        for(int n = 1; n <= N; n++) {
            for(int k = 1; k <= K; k++) {
                int plate_beauty;
                cin >> plate_beauty;
                stacks_of_plates[n][k] = plate_beauty;
            }
        }

        vector<vector<int>> sofxp(N+1, vector<int>(K+1, 0));  // Sum Of First X Plates

        for(int n = 1; n <= N; n++) {
            for(int k = 1; k <= K; k++) {
                sofxp[n][k] = sofxp[n][k-1] + stacks_of_plates[n][k];
            }
        }

        // cout << "sofxp: " << endl;
        // print_matrix(sofxp);
        vector<vector<int>> dp(N+1, vector<int>(P+1, 0));

        for(int n = 1; n <= N; n++) {
            for(int p = 1; p <= P; p++) {
                for(int x = 0; x <= min(p, K); x++) {
                    dp[n][p] = max(dp[n][p], sofxp[n][x] + dp[n-1][p-x]);
                }
            }
        }

        // cout << "dp: " << endl;
        // print_matrix(dp);
        cout << "Case #" << t << ": " << dp[N][P] << "\n";
    }
}