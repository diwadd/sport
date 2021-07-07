#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        ulli N;
        cin >> N;

        ulli mod_7 = 1000000000 + 7;

        ulli res = N;
        ulli lcm_val = 1;
        for(int i = 1; i <= N; i++) {

            lcm_val = lcm(lcm_val, i);

            ulli d = N/lcm_val;
            if(d == 0)
                break;

            res = ( res % mod_7 + d % mod_7 ) % mod_7;

        }

        cout << res << "\n";
    }
}