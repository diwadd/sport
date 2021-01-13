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
 
        int N;
        ulli X;
        cin >> N >> X;

        ulli max_b = 0;
        ulli min_b = 0;
        for(int i = 0; i < N; i++) {
            ld a;
            cin >> a;
            max_b += ulli(ceil(a/ld(X)));
            min_b += ulli(a);
        }
        
        cout << ulli(ceil(ld(min_b)/ld(X))) << " " << ulli(max_b) << "\n";
    }
}
