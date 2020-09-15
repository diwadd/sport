#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double long_double;


int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        lli x, y, k;
        cin >> x >> y >> k;
 
        lli n = ceil((long_double(y)*long_double(k) + long_double(k) - long_double(1.0)) / (long_double(x) -long_double(1.0)));
        cout << n + k << "\n";
    }
}