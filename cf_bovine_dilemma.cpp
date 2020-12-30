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
    
        int N;
        cin >> N;
    
        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }
    
        set<int> bases;
        for(int i = 0; i< N; i++) {
            int xi = a_vec[i];
            for(int j = i + 1; j < N; j++) {
                int xj = a_vec[j];
                int d = abs(xi - xj);
                bases.insert(d);
            }
        }
    
        cout << bases.size() << "\n";
    
    }
}