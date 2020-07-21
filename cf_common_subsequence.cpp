#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N, M;
        cin >> N >> M;
 
        vector<int> a_vec(N, 0);
        vector<int> b_vec(M, 0);
        for(int n = 0; n < N; n++) {
            int a;
            cin >> a;
            a_vec[n] = a;
        }
 
        for(int m = 0; m < M; m++) {
            int b;
            cin >> b;
            b_vec[m] = b;
        }
 
        set<int> u_set;
        bool found  = false;
        if(N < M) {
            for(int n = 0; n < N; n++) {
                u_set.insert(a_vec[n]);
            }
 
            for(int m = 0; m < M; m++) {
                auto it = u_set.find(b_vec[m]);
                if(it != u_set.end()){
                    cout << "YES\n1 " << b_vec[m] << "\n";
                    found  = true;
                    break;
                }
            }
        } else {
            for(int m = 0; m < M; m++) {
                u_set.insert(b_vec[m]);
            }
 
            for(int n = 0; n < N; n++) {
                auto it = u_set.find(a_vec[n]);
                if(it != u_set.end()){
                    cout << "YES\n1 " << a_vec[n] << "\n";
                    found = true;
                    break;
                }
            }
        }
 
        if(found == false) {
            cout << "NO\n";
        }
 
 
    }
}