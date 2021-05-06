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
    
        string s;
        cin >> s;
    
        vector<int> seen_letters(s.size() + 1, 0);
        char prev = s[0];
        seen_letters[s[0] - 'A'] = 1;
        bool is_ok = true;
        for(int i = 1; i < s.size(); i++) {
    
            if(s[i] == prev) {
                continue;
            } else {
    
                int l_index = s[i] - 'A';
    
                if(seen_letters[l_index] != 0) {
                    is_ok = false;
                    break;
                } else if(seen_letters[l_index] == 0) {
                    seen_letters[l_index] = 1;
                    prev = s[i];
                }
            }
        }
    
        if(is_ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    
    }
    
    
}