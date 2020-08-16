#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    lli R, G, B;
    cin >> R >> G >> B;


    vector<int> r_vec(R, 0);
    vector<int> g_vec(G, 0);
    vector<int> b_vec(B, 0);

    for(int i = 0; i < R; i++)
        cin >> r_vec[i];

    for(int i = 0; i < G; i++)
        cin >> g_vec[i];

    for(int i = 0; i < B; i++)
        cin >> b_vec[i];

    sort(r_vec.rbegin(), r_vec.rend());
    sort(g_vec.rbegin(), g_vec.rend());
    sort(b_vec.rbegin(), b_vec.rend());


    vector<vector<vector<int>>> dp(R+1, vector<vector<int>>(G+1, vector<int>(B+1, 0)));

    int res = 0;
    for(int r = 0 ; r < R+1; r++) {
        for(int g = 0; g < G+1; g++) {
            for(int b = 0; b < B+1; b++) {

                if(r < R && g < G) {
                    dp[r+1][g+1][b] = max(dp[r+1][g+1][b], dp[r][g][b] + r_vec[r]*g_vec[g]);
                }
                if(r < R && b < B) {
                    dp[r+1][g][b+1] = max(dp[r+1][g][b+1], dp[r][g][b] + r_vec[r]*b_vec[b]);
                }
                if(b < B && g < G) {
                    dp[r][g+1][b+1] = max(dp[r][g+1][b+1], dp[r][g][b] + g_vec[g]*b_vec[b]);
                }

                res = max(res, dp[r][g][b]);

            }
        }
    }

    cout << res << "\n";

}