#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 1; t <= T; t++) {
 
        int N;
        cin >> N;
 
        vector<int> a_vec(N, 0);
        for(int n = 0; n < N; n++) {
            cin >> a_vec[n];
        }
 
        bool is_ok = false;
        int ix = 0;
        int jx = 0;
        int kx = 0;
        for(int i = 0; i < N-2; i++) {
            for(int j = N-1; j > i+1; j--) {
 
                int maximal = a_vec[j] - a_vec[i];
                if(a_vec[i] > maximal) {
                    break;
                }
                
                for(int k = i + 1; k < j; k++) {
                    if(a_vec[k] <= maximal) {
                        is_ok = true;
                        ix = i;
                        jx = j;
                        kx = k;
                        break;
                    }
                }
                if(is_ok == true)
                    break;
            }
            if(is_ok == true)
                break;
        }
 
        if(is_ok == true)
            cout << ix+1 << " " << kx+1 << " " << jx+1 << "\n";
        else
            cout << "-1\n";
 
 
    }
}