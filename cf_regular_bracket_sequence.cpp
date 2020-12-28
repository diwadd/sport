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

        char fc = 'x';
        char sc = 'x';
        int n_q = 0;

        for(int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == ')') {                
                if(fc == 'x') {
                    fc = s[i];
                } else {
                    sc = s[i];
                }
            }

            if(s[i] == '?') {
                n_q++;
            }
        }

        if(fc == '(' && sc == ')') {
            if(n_q % 2 == 0) {
                cout << "YES\n";
                continue;
            } else {
                cout << "NO\n";
                continue;
            }
        }


        if(s[0] == ')' || s[s.size()-1] == '(') {
            cout << "NO\n";
            continue;
        }

        if(n_q % 2 == 0) {
            cout << "YES\n";
            continue;
        } else {
            cout << "NO\n";
            continue;
        }

    }

}