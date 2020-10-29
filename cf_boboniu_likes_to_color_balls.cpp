#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;


int get_parity(int r, int g, int b, int w) {

        int parity = 0;
        if(r % 2 != 0)
            parity++;
        if(g % 2 != 0)
            parity++;
        if(b % 2 != 0)
            parity++;
        if(w % 2 != 0)
            parity++;

    return parity;
}


int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        int parity = get_parity(r, g, b, w);
 
        if(parity <= 1)
            cout << "YES\n";
        else if (r > 0 && g > 0 && b > 0) {
            parity = get_parity(r-1, g-1, b-1, w+1);
            if(parity <= 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
                cout << "NO\n";
        }

 
    }
}