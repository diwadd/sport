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
    
        int n, l, r;
        cin >> n >> l >> r;
    
        int m = n + 1;
        vector<int> left_colors(m, 0);
        vector<int> right_colors(m, 0);
    
        for(int i = 0; i < l; i++) {
            int sock;
            cin >> sock;
            left_colors[sock]++;
        }
    
        for(int i = 0; i < r; i++) {
            int sock;
            cin >> sock;
            right_colors[sock]++;
        }
    
        int res = 0;
        for(int i = 0; i < m; i++) {
            int delta = min(left_colors[i], right_colors[i]);
            left_colors[i] -= delta;
            right_colors[i] -= delta;
        }
    
        int n_left = 0;
        int n_right = 0;
    
        for(int i = 0; i < m; i++) {
            n_left += left_colors[i];
            n_right += right_colors[i];
        }
        
        if(n_left == n_right) {
            res += n_right;
        } else {
    
            vector<int> *vr = &right_colors;
            vector<int> *vl = &left_colors;
    
            if(n_right < n_left) {
                swap(n_right, n_left);
                swap(vr, vl);
            }
    
            for(int i = 0; i < m; i++) {
                if(vr->at(i) > 1) {
                    int delta = vr->at(i) / 2;
                    int possible_delta = (n_right - n_left) / 2;
        
                    if(possible_delta <= 0)
                        break;
    
                    int real_delta = min(2 * delta, 2 * possible_delta);
                    vr->at(i) -= real_delta;
                    res += real_delta / 2;
                    n_right -= real_delta;
                }
            }
    
            res += n_right;
    
        }
    
        cout << res << "\n";
    
    }
    
    
}