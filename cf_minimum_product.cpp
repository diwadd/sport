#include <bits/stdc++.h> 
 
using namespace std;
typedef unsigned long long int ulli;
 
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
 
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
 
        int dax = a - x;
        int dby = b - y;
 
        // cout << "dax: " << dax << " dby: " << dby << "\n";
        if(dax + dby <= n) {
            cout << ulli(x)*ulli(y) << "\n";
            continue;
        }
 
        ulli min_val = numeric_limits<ulli>::max();
        int new_a, new_b, new_n;
 
        new_a = a; new_b = b; new_n = n;
        int a_sub = min(new_n, dax);
        new_a = new_a - a_sub;
        new_n = new_n - a_sub;
        // cout << "new_n: " << new_n << "\n";
        if(new_n > 0) {
            int b_sub = min(new_n, dby);
            new_b = new_b - b_sub;
        }
 
        // cout << "new_a: " << new_a << " new_b: " << new_b << "\n";
        if(min_val > ulli(new_a) * ulli(new_b)) {
            min_val = ulli(new_a) * ulli(new_b);
        }
 
        new_a = a; new_b = b; new_n = n;
        int b_sub = min(new_n, dby);
        new_b = new_b - b_sub;
        new_n = new_n - b_sub;
        // cout << "new_n: " << new_n << "\n";
        if(new_n > 0) {
            int a_sub = min(new_n, dax);
            new_a = new_a - a_sub;
        }
 
        // cout << "new_a: " << new_a << " new_b: " << new_b << "\n";
        if(min_val > ulli(new_a) * ulli(new_b)) {
            min_val = ulli(new_a) * ulli(new_b);
        }
 
        cout << min_val << "\n";
    }
}