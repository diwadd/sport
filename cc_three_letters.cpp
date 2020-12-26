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
 
        string s;
        cin >> s;

        const int N_LETTERS = 26;
        vector<int> freq(N_LETTERS, 0);

        for(int i = 0; i < s.size(); i++) {
            freq[s[i]-'a']++;
        }

        int n_pairs = 0;
        int n_singles = 0;
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] % 2 == 0 ) {
                n_pairs += freq[i]/2;
            } else {
                n_pairs += (freq[i] - 1)/2;
                n_singles += 1;
            }
        }

        int gold_coins = 0;

        if(n_singles > 0 && n_pairs > 0) {
            gold_coins = min(n_pairs, n_singles);
            n_pairs = max(0, n_pairs-n_singles);
        }

        gold_coins += int(2*n_pairs) / 3; 

        cout << gold_coins << "\n";

    }

}