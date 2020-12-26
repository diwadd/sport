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
        string p;

        cin >> s >> p;

        int o_unresolved = 0;
        int z_unresolved = 0;
        for(int i = 0; i < N; i++) {
            if(s[i] == '1' && p[i] == '0') {
                o_unresolved++;
            } else if (s[i] == '0' && p[i] == '1') {
                if(o_unresolved > 0) {
                    o_unresolved--;
                } else {
                    z_unresolved++;
                }
            }
        }

        if(o_unresolved == 0 && z_unresolved == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}