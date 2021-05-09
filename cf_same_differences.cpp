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

        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
            a_vec[i] -= (i + 1);
        }

        vector<ulli> occ(N, 0);
        map<int,ulli> freq;
        for(int i = N-1; i >= 0; i--) {

            if(freq.find(a_vec[i]) != freq.end()) {
                freq[a_vec[i]]++;
                occ[i] = freq[a_vec[i]];
            } else {
                freq[a_vec[i]] = 0;
                occ[i] = freq[a_vec[i]];
            }

        }

        ulli res = 0;
        for(int i = 0; i < N; i++) {
            res += occ[i];
        }

        cout << res << "\n";
    }


}