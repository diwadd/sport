#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
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
 
        int N;
        cin >> N;
 
        vector<int> a_vec(N, 0);
        vector<int> b_vec(N, 0);
 
        string a, b;
        cin >> a;
        cin >> b;
 
        if(N == 1){
            if(a[0] != b[0]){
                cout << "1 1\n";
                continue;
            }
        }
 
        for(int i = 0; i < a.length(); i++) {
            if(a[i] == '1'){
                a_vec[i] = 1;
            } else {
                a_vec[i] = 0;
            }
 
            if(b[i] == '1'){
                b_vec[i] = 1;
            } else {
                b_vec[i] = 0;
            }
        }
 
        vector<int> a_moves;
        a_moves.reserve(2*N);
        for(int i = 0; i < N-1; i++) {
            if(a_vec[i] != a_vec[i + 1]) {
                a_moves.push_back(i);
            }
        }
 
        if(a_vec[N-1] == 1){
            a_moves.push_back(N - 1);
        }
 
        vector<int> b_moves;
        b_moves.reserve(2*N);
 
        for(int i = 0; i < N-1; i++) {
            if(b_vec[i] != b_vec[i + 1]) {
                b_moves.push_back(i);
            }
        }
 
        if(b_vec[N-1] == 1){
            b_moves.push_back(N - 1);
        }
        reverse(begin(b_moves), end(b_moves));
 
        // cout << "Three vectors:" << endl;
        // print_vector(a_vec);
        // print_vector(a_moves);
        // print_vector(b_moves);
 
        cout << a_moves.size() + b_moves.size() << " ";
        for(int i = 0; i < a_moves.size(); i++) {
            cout << a_moves[i] + 1 << " ";
        }
 
        if(b_moves.size() > 0){
            for(int i = 0; i < b_moves.size() - 1; i++) {
                cout << b_moves[i] + 1 << " ";
            }
            cout << b_moves[b_moves.size() - 1] + 1 << "\n";
        }
        else {
            cout << "\n";
        }
 
    }
}