#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int n, k;
        cin >> n >> k;

        if(n < k)
            cout << k - n << "\n";
        else {
            if((n-k) % 2 == 0){
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        }
    }
}