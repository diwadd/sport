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
 
        vector<lli> a_vec(N, 0);
        lli even = 0;
        for(int n = 0; n < N; n++) {
            lli a;
            cin >> a;
            a_vec[n] = a;
            if (n % 2 == 0)
                even += a;
        }
 
        lli cm = 0;
        lli bm = 0;
        for(int i = 1; i < N; i = i + 2) {
            lli x = a_vec[i] - a_vec[i - 1];
            cm = max(0ll, cm + x);
            bm = max(bm, cm);
        }
 
        cm = 0;
        for(int i = 2; i < N; i = i + 2) {
            lli x = a_vec[i - 1] - a_vec[i];
            cm = max(0ll, cm + x);
            bm = max(bm, cm);
        }
 
        lli res = even + bm;
 
        cout << res << "\n";
    }
}