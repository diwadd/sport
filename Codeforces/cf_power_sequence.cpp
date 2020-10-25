#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int N;
    cin >> N;
 
    vector<int> a_vec(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> a_vec[i];
    }
 
    sort(a_vec.begin(), a_vec.end());
    // print_vector(a_vec);
 
    int down = floor( powl( ld(a_vec[N-1]), 1.0 / ld(N-1)) );
    int top = ceil( powl( ld(a_vec[N-1]), 1.0 / ld(N-1)) );
 
    // cout << "down: " << down << " top: " << top << "\n";
 
    ulli cost_down = 0;
    ulli cost_top = 0;
 
    for(int i = 0; i < N; i++) {
        cost_down += abs(lli(a_vec[i]) - lli(pow(ld(down), i)));
        cost_top += abs(lli(a_vec[i]) - lli(pow(ld(top), i)));
    }
 
    if(cost_down < cost_top) {
        cout << cost_down << "\n";
    } else {
        cout << cost_top << "\n";
    }
 
}