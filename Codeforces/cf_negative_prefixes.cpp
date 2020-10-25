#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double long_double;
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(ulli i = 0; i < vec.size(); i++) {
        if(i != vec.size()-1)
            cout << vec[i] << " ";
        else
            cout << vec[i];
    }
    cout << "\n";
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
        for(int n = 0; n < N; n++) {
            cin >> a_vec[n];
        }
 
        int n_lock = 0;
        vector<int> locked_marker(N, 0);
        for(int n = 0; n < N; n++) {
            int c;
            cin >> c;
 
            if(c == 1)
                n_lock++;
            locked_marker[n] = c;
        }
 
        vector<int> unlocked;
        unlocked.reserve(n_lock);
        for(int n = 0; n < N; n++) {
            if(locked_marker[n] == 0){
                unlocked.push_back(a_vec[n]);
            }
 
        }
 
        sort(unlocked.rbegin(), unlocked.rend());
 
        int index = 0;
        vector<int> sol(N, 0);
        for(int n = 0; n < N; n++) {
            if(locked_marker[n] == 1) {
                sol[n] = a_vec[n];
            } else {
                sol[n] = unlocked[index];
                index++; 
            }
        }
 
        print_vector(sol);
 
    }
}