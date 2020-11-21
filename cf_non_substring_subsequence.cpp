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
    
        int N, Q;
        cin >> N >> Q;
    
        string s;
        cin >> s;
    
        vector<int> zeros(N, 0);
        vector<int> ones(N, 0);
    
        if(s[0] == '1'){
            ones[0] = 1;
        } else {
            zeros[0] = 1;
        }
    
        for(int i = 1; i < N; i++) {
            if(s[i] == '1') {
                ones[i] = ones[i-1] + 1;
                zeros[i] = zeros[i-1];
            } else {
                zeros[i] = zeros[i-1] + 1;
                ones[i] = ones[i-1];
            }
        }

        for(int q = 0; q < Q; q++) {
            int l, r;
            cin >> l >> r;
    
            l = l - 1;
            r = r - 1;
    
            int zttl, ottl;
            if(s[l] == '0') {
                zttl = max(zeros[l] - 1, 0);
            } else {
                zttl = zeros[l];
            }
    
            if(s[l] == '1') {
                ottl = max(ones[l] - 1, 0);
            } else {
                ottl = ones[l];
            }
    
            int zttr = zeros[N-1] - zeros[r];
            int ottr = ones[N-1] - ones[r];
    
            if(s[r] == '0' && zttr > 0) {
                cout << "YES\n";
            } else if (s[r] == '1' && ottr > 0) {
                cout << "YES\n";
            } else if (s[l] == '0' && zttl > 0) {
                cout << "YES\n";
            } else if (s[l] == '1' && ottl > 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}