#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        int d = min(z1, y2);
        int c = 2 * d;
        z1 -= d; y2 -= d;

        d = min(z1, z2);
        z1 -= d; z2 -= d;

        d = min(z2, x1);
        z2 -= d; x1 -= d;

        d = min(y1, y2);
        y1 -= d;

        d = min(y1, x2);
        y1 -= d; x2 -= d;

        c -= 2*min(y1, z2);
        cout << c << "\n";

    }
}