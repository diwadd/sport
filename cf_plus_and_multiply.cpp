#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ulli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        ulli n, a, b;
        cin >> n >> a >> b;

        if(a == 1) {
            if((n-1) % b == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            continue;
        }

        if(b == 1) {
            cout << "Yes\n";
            continue;
        }

        // No idea why this condition does not work
        // for the given series.
        // if( n % a == 0) {
        //     cout << "Yes\n";
        //     continue;
        // }

        bool is_ok = false;
        for(ulli i = 1; i <= n; i = i * a) {
            // chrono::milliseconds ts(1000);
            // this_thread::sleep_for(ts);

            if( (n - i) % b == 0 ) {
                cout << "Yes\n";
                is_ok = true;
                break;
            }
        }

        if(is_ok == false) {
            cout << "No\n";
        }

    }
}
