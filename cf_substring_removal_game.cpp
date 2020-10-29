#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

template<typename T> void print_vector(vector<T> &vec) {

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        string s;
        cin >> s;

        vector<int> n_ones;
        n_ones.reserve(s.size() / 2 + 1);

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '0')
                continue;

            int co = 0;
            for(int j = i; j < s.size(); j++) {
                if(s[j] == '1') {
                    co++;
                    if (j == s.size()-1)
                        i = j;
                } else {
                    i = j;
                    break;
                }
            }
            n_ones.push_back(co);
        }

        sort(n_ones.rbegin(), n_ones.rend());
        // print_vector(n_ones);

        int res = 0;
        for(int i = 0; i < n_ones.size(); i = i + 2) {
            res = res + n_ones[i];
        }
        cout << res << "\n";

    }
}