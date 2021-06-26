#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        string s;
        cin >> s;

        if(s[0] == '1'){
            string s1(1, s[0]);
            string s2(1, '0');
            string s3 = s.substr(1, s.size());
            cout << s1+s2+s3 << "\n";
        } else {
            cout << string(1, '1') + s << "\n";
        }
    }
}
