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
 
        int N, K;
        cin >> N >> K;

        int s = 0;
        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            s += a;
        }

        if(s % K == 0) {
            cout << "0\n";
        } else {
            cout << "1\n";
        }

    }
}