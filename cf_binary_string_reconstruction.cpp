#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        string s;
        cin >> s;

        int x;
        cin >> x;

        int n = s.size();

        // Move to 1 based indexing
        s = "z" + s;
 
        string w(n + 1, '1');
        for(int i = 1; i <= n; i++) {
            if(s[i] == '0'){

                int i_w = i - x;
                if(i_w >= 1 && i_w <= n){
                        w[i_w] = '0';
                }   

                i_w = i + x;
                if(i_w >= 1 && i_w <= n){
                    w[i_w] = '0';
                }
            }
        }

        // cout << "w: " << w << "\n";

        string new_s(n+1, '0');
        for(int i = 1; i <= n; i++) {
            if(i - x >= 1) {
                if(w[i - x] == '1') {
                    new_s[i] = '1';
                }
            }
            if(i + x <= n) {
                if(w[i + x] == '1') {
                    new_s[i] = '1';
                }
            }
        }

        // cout << "new_s: " << new_s << "\n";

        bool is_ok = true;
        for(int i = 1; i <= n; i++) {
            if(new_s[i] != s[i]) {
                is_ok = false;
                break;
            }
        }
 
        if(is_ok == false) {
            cout << "-1\n";
        } else {
            cout << w.substr(1, n) << "\n";
        }
    }
}