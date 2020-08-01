#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 1; t <= T; t++) {
 
        lli N;
        cin >> N;
 
        int n_eights = floor(N/4);
        string s0(n_eights,'8'); 
 
        int n_nines = N - n_eights;
 
        string s9(n_nines, '9');
        if(N % 4 != 0){
            s9[s9.length() - 1] = '8';
        }
 
        cout << s9 + s0 << "\n";
    }
}