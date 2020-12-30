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
    
        vector<int> x_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> x_vec[i];
        }
    
        int current = x_vec[0];
        int freq = 1;
        for(int i = 1; i < N; i++) {
            if(current == x_vec[i]) {
                freq++;
                continue;
            } else if (current != x_vec[i]) {
    
                if(freq > 1) {
                    x_vec[i-1]++;
                    if(x_vec[i-1] == x_vec[i]){
                        current = x_vec[i];
                        freq = 2;
                    } else {
                        current = x_vec[i];
                        freq = 1;
                    }
                } else if (freq == 1) {
                    current = x_vec[i];
                    freq = 1; 
                }
            }
        }
    
        if(current == x_vec[N-1] && freq > 1) {
            x_vec[N-1]++;
        }
    
        set<int> s(x_vec.begin(), x_vec.end());
    
        cout << s.size() << "\n";
    
    }
}