#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
 
    string s;
    cin >> s;

    int N_LETTERS = 27;
    vector<vector<int>> prefix_sums(N+1, vector<int>(N_LETTERS, 0));

    for(int i = 1; i <= N; i++) {

        for(int j = 0; j < N_LETTERS; j ++) {
            prefix_sums[i][j] = prefix_sums[i-1][j];
        }

        prefix_sums[i][s[i-1] - 'a']++;
    }

    for(int q = 0; q < Q; q++) {
 
        int l, r;
        cin >> l >> r;


        int res = 0;
        for(int i = 0; i < N_LETTERS; i++) {
            res = res + (i+1)*(prefix_sums[r][i] - prefix_sums[l-1][i]);
        }

        cout << res << "\n";

    }
}