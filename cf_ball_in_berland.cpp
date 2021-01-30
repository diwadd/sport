#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int a, b, k;
        cin >> a >> b >> k;
        
        vector<int> a_vec(k, 0);
        vector<int> b_vec(k, 0);

        for(int i = 0; i < k; i++) {
            cin >> a_vec[i];
            a_vec[i]--;
        }

        for(int i = 0; i < k; i++) {
            cin >> b_vec[i];
            b_vec[i]--;
        }

        vector<int> a_deg(a, 0);
        vector<int> b_deg(b, 0);

        for(int i = 0; i < k; i++){
            a_deg[a_vec[i]]++;
            b_deg[b_vec[i]]++;
        }

        ulli res = 0;
        for(int i = 0; i < k; i++){
            res = res + ulli(k - a_deg[a_vec[i]] - b_deg[b_vec[i]] + 1);
        }

        cout << res/2 << "\n";

    }
}