#include <bits/stdc++.h> 

using namespace std;

int get_value(int n,
              int c, 
              vector<int> &w_vec,
              vector<int> &v_vec,
              vector<vector<int>> &dp) {

    if(dp[n][c] != -1) {
        return dp[n][c];
    }

    if(n == 0 || c == 0) {
        return 0;
    } else if (w_vec[n] > c) {
        return get_value(n - 1, c, w_vec, v_vec, dp);
    } else {
        int r1 = get_value(n - 1, c, w_vec, v_vec, dp);
        int r2 = v_vec[n] + get_value(n - 1, c - w_vec[n], w_vec, v_vec, dp);

        int res = max(r1, r2);
        dp[n][c] = res;
        return res;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c = 0;
    int n = 0;

    cin >> c >> n;

    vector<pair<int, int>> wv_vec(n + 1, pair<int, int>(0, 0));
    for(int i = 1; i <= n; i++) {
        cin >> wv_vec[i].first;
        cin >> wv_vec[i].second;
    }

    sort(wv_vec.begin(), wv_vec.end(),  
        [](auto &left, auto &right) {
            return left.first < right.first;
    });

    vector<int> w_vec(n+1, 0);
    vector<int> v_vec(n+1, 0);

    for(int i = 0; i <= n; i++) {
        w_vec[i] = wv_vec[i].first;
        v_vec[i] = wv_vec[i].second;
    }

    vector<vector<int>> dp(n+1, vector<int>(c+1, -1));
    int res = get_value(n, c, w_vec, v_vec, dp);
    cout << res << "\n";
}
