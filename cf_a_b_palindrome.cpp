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
 
        int na, nb;
        cin >> na >> nb;

        int a = na;
        int b = nb;

        string s;
        cin >> s;

        int n = s.size();

        bool is_ok = true;
        for(int i = 0; i <= n/2; i++) {
            if(s[i] != s[n-1-i] && (s[i] != '?' && s[n-1-i] != '?')) {
                is_ok = false;
                break;
            }
        }

        if(is_ok == false) {
            cout << "-1\n";
            continue;
        }


        if (n % 2 != 0) {
            int mid = n/2;
            if(s[mid] == '?') {
                if(a % 2 != 0 && b % 2 == 0) {
                    a--;
                    s[mid] = '0';
                } else if (a % 2 == 0 && b % 2 != 0) {
                    b--;
                    s[mid] = '1'; 
                } else if (a % 2 != 0 && b % 2 != 0) {
                    cout << "-1\n";
                    continue;
                }
            } else if(s[mid] == '0') {
                a--;
            } else if(s[mid] == '1') {
                b--;
            }
        }

        int mid = n/2 - 1;

        for(int i = 0; i <= mid; i++) {

            if(i == n-1-i) {
                continue;
            } else if(s[i] == s[n-1-i] && (s[i] == '0' && s[n-i-1] == '0')) {
                a -= 2;
            } else if(s[i] == s[n-1-i] && (s[i] == '1' && s[n-i-1] == '1')) {
                b -= 2;
            }
        }


        for(int i = 0; i <= mid; i++) {

            if(i == n-1-i) {
                continue;
            } else if(s[i] == '?' && s[n-1-i] == '0') {
                if(a > 0) {
                    a -= 2;
                    s[i] = '0';
                }
            } else if(s[i] == '0' && s[n-1-i] == '?') {
                if(a > 0) {
                    a -= 2;
                    s[n-i-1] = '0';
                }
            } else if(s[i] == '?' && s[n-1-i] == '1') {
                if (b > 0) {
                    b -= 2;
                    s[i] = '1';
                }
            } else if(s[i] == '1' && s[n-1-i] == '?') {
                if (b > 0) {
                    b -= 2;
                    s[n-1-i] = '1';
                }
            } 
        }

        for(int i = 0; i <= mid; i++) {
            if(s[i] == '?' && s[n-1-i] == '?') {
                if(a >= b && a > 1) {
                    a -= 2;
                    s[i] = '0';
                    s[n-i-1] = '0';
                } else if(b >= a && b > 1) {
                    b -= 2;
                    s[i] = '1';
                    s[n-i-1] = '1';
                }
            }
        }

        int la = 0;
        int lb = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0')
                la++;
            else
                lb++;
        }

        if(is_ok == false) {
            cout << "-1\n";
        } else {
            if (la == na && lb == nb) {
                cout << s << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
}