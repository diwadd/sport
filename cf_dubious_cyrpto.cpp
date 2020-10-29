#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        lli l, r, m;
        cin >> l >> r >> m;

        lli a, b, c;
        for(int ia = l; ia <= r; ia++) {

            lli modulo_one = m % ia;
            lli modulo_two = ia - modulo_one;

            if(modulo_one <= r - l && modulo_one != m) {
                a = ia;
                c = l;
                b = modulo_one + c;
            } else if(modulo_two <= r - l) {
                a = ia;
                b = l;
                c = modulo_two + b;
            }
        }

        cout << a << " " << b << " " << c << "\n";
    }
}