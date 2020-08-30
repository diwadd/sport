#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;
 
        int MAX_LETTERS = 26;
        vector<int> freq(MAX_LETTERS, 0);
        // vector<string> s_vec(N);
        for(int n = 0; n < N; n++) {
 
            string s;
            cin >> s;
 
            for(int i = 0; i < s.size(); i++) {
                freq[int(s[i] - 'a')]++;
            }
 
        }
 
        bool is_ok = true;
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] % N != 0) {
                is_ok = false;
            }
        }
 
        if(is_ok == true)
            cout << "YES\n";
        else
            cout << "NO\n";
 
    }
}