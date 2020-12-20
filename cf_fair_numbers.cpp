#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

bool is_fair(ulli n) {

    ulli old_n = n;
    while(n > 0) {
        ulli d = n % 10;
        if(d > 1 && old_n % d != 0)
            return false;
        n = n / 10;
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        ulli N;
        cin >> N;

        while(true) {
            if(is_fair(N) == true) {
                cout << N << "\n";
                break;
            } else {
                N++;
            }
        }

    }


}