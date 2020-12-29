#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;

        vector<int> r_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> r_vec[i];
        }

        int M;
        cin >> M;
        vector<int> b_vec(M, 0);
        for(int i = 0; i < M; i++) {
            cin >> b_vec[i];
        }

        vector<vector<int>> dp(N+1, vector<int>(M+1, numeric_limits<int>::min()));
        dp[0][0] = 0;
        int res = 0;
        for(int i = 0; i < N+1; i++) {
            for(int j = 0; j < M+1; j++) {

                if(i < N) {
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + r_vec[i]);
                }

                if(j < M) {
                    dp[i][j+1] = max(dp[i][j+1], dp[i][j] + b_vec[j]);
                }
                res = max(res, dp[i][j]);
            }
        }
        cout << res << "\n";

    }
}