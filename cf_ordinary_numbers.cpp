#include <bits/stdc++.h> 
    
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int build_base(int m) {
    
    if(m <= 0)
        return 1;
    
    int b = pow(10, m);
    return b + build_base(m - 1);
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++) {
    
        int N;
        cin >> N;
    
        int m = floor(log10(ld(N)));
    
        int N_ORD_NUMS = 9;
        int res = N_ORD_NUMS*m;
    
        int base_ord_int = build_base(m);

        vector<int> v;
        v.reserve(N_ORD_NUMS);
        for(int i = 1; i <= N_ORD_NUMS; i++) {
            v.push_back(i*base_ord_int);
        }
    
        int index = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] <= N)
                index = i+1;
            else {
                break;
            }
        }

        res += index;
        cout << res << "\n";
    }

}