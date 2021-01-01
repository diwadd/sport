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
 
        int a, b, c;
        cin >> a >> b >> c;

        int d = (a+b+c) % 9;
        int k = (a+b+c) / 9;

        if(d == 0 && (a >= k && b >= k && c >= k)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }


}