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
        cin >> N;
    
        if(N == 1){
            cout << "0\n";
        } else if (N == 2) {
            cout << "1\n";
        } else if (N == 3) {
            cout << "2\n";
        } else if (N % 2 == 0) {
            cout << "2\n";
        } else if (N % 2 != 0) {
            cout << "3\n";
        }
    }
}