#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        ulli A, B;
        cin >> A >> B;

        if( (B & (B - 1)) == 0 ) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}