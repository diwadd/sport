#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
 
void left_just(string &s, int n, char c = ' ') {
    while(s.length() < n) {
        s = c + s;
    }
}
 
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
 
template<typename T> void print_matrix(vector<vector<T>> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        print_vector(mat[i]);
    }
}
 
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;
 
        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }
 
        set<int> s(a_vec.begin(), a_vec.end());
        if(s.size() == 1) {
            cout << "-1\n";
            continue;
        }
 
        int max_p = (*s.rbegin());
        // cout << "max_p: " << max_p << endl;
        int index = -1;
        for(int i = 0; i < N; i++) {
            if(i - 1 >= 0 && i + 1 <= N - 1) {
                // cout << "a_vec[i]: " << a_vec[i] << endl;
                if(a_vec[i] == max_p && (a_vec[i-1] < max_p || a_vec[i+1] < max_p)) {
                    index = i;
                    break;
                }
            }
        }
 
        // cout << "index: " << index << endl;
        if(index != -1){
            cout << index+1 << "\n";
        } else {
            if(a_vec[0] == max_p && a_vec[1] < max_p) {
                cout << "1\n";
            } else if (a_vec[N-1] == max_p && a_vec[N-2] < max_p) {
                cout << N << "\n";
            }
        }
 
    }
}