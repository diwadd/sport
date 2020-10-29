#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
 
int process(string &s) {
 
    int res = 0;
    for(int init = 0; true; init++) {
        
        int cur = init;
        bool ok = true;
        cout << "init: " << init << endl;
        for(int i = 0; i < s.length(); i++) {
            cout << "Adding to res..." << endl;
            res++;
            if(s[i] == '+')
                cur++;
            else
                cur--;
        
            if(cur < 0) {
                ok = false;
                break;
            }
        }
        if(ok == true)
            break;
    }
    return res;
}
 
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        string s;
        cin >> s;
 
        // cout << process(s) << endl;
 
        lli N = s.length();
        vector<lli> prefix_sum(N+1, 0);
        if(s[0] == '+') {
            prefix_sum[1] = 1;
        } else {
            prefix_sum[1] = -1;
        }
 
        vector<lli> f_vec_v2(N + 1, -1);
 
        if(prefix_sum[1] == -1){
            f_vec_v2[1] = 1;
        }
 
        for(lli i = 1; i < N; i++) {
            if(s[i] == '+') {
                prefix_sum[i+1] = prefix_sum[i] + 1;
            } else {
                prefix_sum[i+1] = prefix_sum[i] - 1;
            }
 
            if(prefix_sum[i+1] >= 0)
                continue;
            lli j  = -1*prefix_sum[i+1];
            if(f_vec_v2[j] == -1) {
                f_vec_v2[j] = i+1;
            }
        }
 
        // vector<int> f_vec(N + 1, -1);
        // for(int i = 1; i < N + 1; i++) {
        //     for(int j = 1; j < N + 1; j++) {
        //         if(prefix_sum[j] == -i){
        //             f_vec[i] = j;
        //             break;
        //         }
        //     }
        // }
 
        // print_vector(prefix_sum);
        // print_vector(f_vec);
        // print_vector(f_vec_v2);
 
        lli res = 0;
        for(lli i = 1; i < N + 1; i++) {
            if(f_vec_v2[i] == -1) {
                res = res + N;
                break;
            } else {
                res = res + f_vec_v2[i];
            }
        }
 
        if(prefix_sum[N] == -1*N){
            res = res + N;
        }
 
        cout << res << "\n";
    }
}