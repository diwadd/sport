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
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }
 
        sort(a_vec.begin(), a_vec.end());
 
        bool is_ok = true;
        for(int i = 0; i < N-1; i++){
            if(abs(a_vec[i] - a_vec[i+1]) > 1){
                is_ok = false;
                break;
            }
        }
 
        if(is_ok == false)
            cout << "NO\n";
        else 
            cout << "YES\n";
 
    }
}