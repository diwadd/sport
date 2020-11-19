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
 
        int x, y;
        cin >> x >> y;
 
        int dx = abs(x);
        int dy = abs(y);
    
        if(dx == 0 && dy == 0) {
            cout << "0\n";
        } else if(dx == 0 || dy == 0) {
            int d = max(dx, dy);
            cout << 2*d-1 << "\n";
        } else if (dx == dy) {
            cout << 2*dx << "\n";
        } else {
            int d_square = min(dx, dy);
            int path = abs(dx - dy);
 
            int res = 2*path - 1 + 2*d_square;
            cout << res << "\n";
        }
    }
}
 
 