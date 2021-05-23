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
 
        int D, d, A, B, C;
        cin >> D >> d >> A >> B >> C;

        int d1 = 10;
        int d2 = 21;
        int d3 = 42;

        int max_d = D * d;

        if(max_d < d1) {
            cout << "0\n";
        } else if(d1 <= max_d && max_d < d2) {
            cout << A << "\n";
        } else if(d2 <= max_d && max_d < d3) {
            cout << B << "\n";
        } else if(d3 <= max_d) {
            cout << C << "\n";
        }
    }
}