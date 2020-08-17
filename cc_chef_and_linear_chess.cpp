#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N, K;
        cin >> N >> K;
        
        vector<int> p_vec(N, 0);

        for(int n = 0; n < N; n++) {
            cin >> p_vec[n];
        }


        int min_moves = numeric_limits<int>::max();
        int player = 0;
        for(int i = 0; i < p_vec.size(); i++) {

            if(p_vec[i] > K) {
                continue;
            }
            
            int m = (K - p_vec[i]) % p_vec[i];

            if(m == 0) {
                int moves = (K - p_vec[i]) / p_vec[i];

                if(moves < min_moves) {
                    min_moves = moves;
                    player = i;
                }
            }

        }

        if(min_moves == numeric_limits<int>::max()) {
            cout << "-1\n";
        } else {
            cout << p_vec[player] << "\n";
        }

    }
}