#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 1; t <= T; t++) {
 
        int n;
        cin >> n;
 
        string s;
        cin >> s;
 
        char c = s[n -1];
        string res(n, c);
 
        cout << res << "\n";
 
    }
}