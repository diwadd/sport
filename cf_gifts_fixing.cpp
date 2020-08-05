#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
 
template<typename T> void print_matrix(vector<vector<T>> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        cout << i << ": ";
        print_vector(mat[i]);
    }
}
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    int n_letters = 20;
    vector<vector<int>> graph(n_letters, vector<int>());
    for(int t = 1; t <= T; t++) {
 
        int N;
        cin >> N;
 
        vector<int> a_vec(N, 0);
        vector<int> b_vec(N, 0);
 
        int a_min = numeric_limits<int>::max();
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
            if(a_vec[i] < a_min)
                a_min = a_vec[i];
        }
 
        int b_min = numeric_limits<int>::max();
        for(int i = 0; i < N; i++) {
            cin >> b_vec[i];
            if(b_vec[i] < b_min)
                b_min = b_vec[i];
        }
 
        vector<int> a_diff(N, 0);
        vector<int> b_diff(N, 0);
 
        for(int i = 0; i < N; i++) {
            a_diff[i] = a_vec[i] - a_min;
            b_diff[i] = b_vec[i] - b_min;
        }
 
        lli res = 0;
        for(int i = 0; i < N; i++) {
            lli d = abs(a_diff[i] - b_diff[i]) + min(a_diff[i], b_diff[i]);
            res = res + d;
        }
 
        cout << res << endl;
    }
}