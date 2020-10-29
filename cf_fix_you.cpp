#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N, M;
        cin >> N >> M;

        vector<string> belt(N, string(M, 'x'));

        for(int i = 0; i < N; i++) {
            string s;
            cin >> s;
            belt[i] = s;
        }

        if(N == 1 && M == 1) {
            cout << "0\n";
            continue;
        }

        int res = 0;
        if(N == 1 && M > 1) {
            for(int i = 0; i < belt[0].size(); i++) {
                if(belt[0][i] == 'D'){
                    res++;
                }
            }
            cout << res << "\n";

        } else if(N > 1 && M == 1) {
            for(int i = 0; i < N; i++) {
                if(belt[i][0] == 'R'){
                    res++;
                }
            }
            cout << res << "\n";

        } else {

            for(int i = 0; i < N; i++) {
                if(belt[i][M-1] == 'R')
                    res++;
            }

            for(int i = 0; i < M; i++) {
                if(belt[N-1][i] == 'D')
                    res++;
            }
            
            cout << res << "\n";
        }

    }
}