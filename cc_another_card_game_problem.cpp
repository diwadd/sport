#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int PC, PR;
        cin >> PC >> PR;

        int nc = PC / 9;
        int nr = PR / 9;

        if(PC % 9 != 0)
            nc++;

        if(PR % 9 != 0)
            nr++;

        if(nc < nr) {
            cout << 0 << " " << nc << "\n";
        } else {
            cout << 1 << " " << nr << "\n";
        }

    }
}