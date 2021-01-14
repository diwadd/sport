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
    
        int N, d;
        cin >> N >> d;
    
        vector<int> a_vec(N, 0);
        bool is_ok = true;
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
            if(a_vec[i] > d)
                is_ok = false;
        }
    
        if(is_ok == true) {
            cout << "YES\n";
            continue;
        }
    
        sort(a_vec.begin(), a_vec.end());
    
        // Per constrains N >= 3
        int a0 = a_vec[0];
        int a1 = a_vec[1];
    
        if(a0 + a1 <= d)
            cout << "YES\n";
        else
            cout << "NO\n";
    
    }
    
}