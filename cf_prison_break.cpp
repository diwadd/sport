#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int n, m, r, c;
        cin >> n >> m >> r >> c;

        int d00 = abs(1 - r) + abs(1 - c);
        int dnm = abs(n - r) + abs(m - c);
        int dn0 = abs(n - r) + abs(1 - c);
        int d0m = abs(1 - r) + abs(m - c);

        // printf("%d %d %d %d\n", d00, dnm, dn0, d0m);

        int res = max(max(max(d00, dnm), dn0), d0m);
        cout << res << "\n";
    }


}