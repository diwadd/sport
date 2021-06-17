#include <bits/stdc++.h> 

using namespace std;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;

        int s12 = max(s1, s2);
        int s34 = max(s3, s4);

        vector<int> s_vec = {s1, s2, s3, s4};

        sort(s_vec.rbegin(), s_vec.rend());

        bool s12_ok = (s12 == s_vec[0] or s12 == s_vec[1]);
        bool s34_ok = (s34 == s_vec[0] or s34 == s_vec[1]);

        if(s12_ok == true and s34_ok == true) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}