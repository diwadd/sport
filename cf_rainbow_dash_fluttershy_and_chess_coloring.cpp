#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 1; t <= T; t++) {
 
        int N;
        cin >> N;
 
        if(N % 2 != 0) {
            int n = (N - 1) / 2;
            cout << n + 1 << "\n";
        } else {
            int n = N / 2;
            cout << n + 1 << "\n";
        }
    }
}