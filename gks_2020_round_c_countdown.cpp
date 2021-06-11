#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {

        int N, K;
        cin >> N >> K;

        vector<int> a_vec(N, 0);
        for(auto &a : a_vec)
            cin >> a;

        // print_vector(a_vec);
        int res = 0;
        for(int i = 0; i < a_vec.size(); i++) {
            int ai = a_vec[i];
            // cout << "ai: " << ai << "\n";
            if(ai == K) {

                int p = ai;
                for(int j = i+1; j < a_vec.size(); j++) {
                    int aj = a_vec[j];
                    // cout << "aj: " << aj;
                    if(p - aj != 1) {
                        // cout << " breaking...\n";
                        break;
                    }
                    if(p - aj == 1 and aj == 1) {
                        // cout << " found m-countdown...\n";
                        res++;
                        i = j;
                        break;
                    }
                    // cout << " moving right...\n";
                    p = aj;
                }
            }
        }

        cout << "Case #" << t <<": " << res << "\n";

    }
}
