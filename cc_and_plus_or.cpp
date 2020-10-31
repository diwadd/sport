#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        ulli x;
        cin >> x;

        // In the constraints there is nothing about a and b
        // so we can chose a = 0 and b = x and (a & b) + (a | b) == x
        // will always hold.

        cout << "0 " << x << "\n"; 
    }


}