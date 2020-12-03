#include <bits/stdc++.h> 
    
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
    
template<typename T> void print_vector(vector<T> &vec) {
    
    int n = vec.size();
    for(int i = 0; i < n; i++) {
        if(i == n - 1)
            cout << vec[i];
        else
            cout << vec[i] << " ";
    }
    cout << "\n";
}
    
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++) {
    
        int N, x;
        cin >> N >> x;
    
        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }
    
        bool is_ok = true;
        for(int i = 1; i < N; i++) {
            if(a_vec[i-1] > a_vec[i]){
                is_ok = false;
            }
        }

        if(is_ok == true) {
            cout << "0\n";
            continue;
        }

        int res = 0;
        for(int i = 0; i < N; i++) {
            if(a_vec[i] > x) {
                int box = x;
                x = a_vec[i];
                a_vec[i] = box;
                res++;
            }

            if(is_sorted(a_vec.begin(), a_vec.end()) == true) {
                break;
            }
        }

        for(int i = 1; i < N; i++) {
            if(a_vec[i-1] > a_vec[i]){
                res = -1;
            }
        }
    
        if(res == -1) {
            cout << "-1\n";
        } else {
            cout << res << "\n";
        }
    
    }
}