#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {

        lli N, D;
        cin >> N >> D;
        
        vector<lli> x_vec(N, 0);
        for(int i = 0; i < N; i++) {
            lli x;
            cin >> x;
            x_vec[i] = x;
        }

        lli factor = 0;
        lli minimal_day = D;

        for(int i = N-1; i >= 0; i--) {
            factor = floor(minimal_day / x_vec[i]);
            minimal_day = factor * x_vec[i];
        }

        cout << "Case #" << t << ": " << minimal_day << "\n";
    }
}