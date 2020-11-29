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
    
        int N, K;
        cin >> N >> K;
    
        vector<int> a_vec(N, 0);
        map<int, int> freq;
        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            a_vec[i] = a;
            freq[a]++;
        }
    
        set<int> a_s(a_vec.begin(), a_vec.end());
        int min_res = numeric_limits<int>::max();

        for(auto it = a_s.begin(); it != a_s.end(); it++) {
            int current_a = *it;
            int res = 0;
            for(int i = 0; i < N; i++) {
                if(a_vec[i] == current_a) {
                    continue;
                }
                int n_houses = 0;
                for(int j = i; j < i + K; j++) {
                    if(j >= N)
                        break;
                    if(a_vec[j] != current_a) {
                        n_houses++;
                    }
                }
                if(n_houses > 0) {
                    res++;
                }
                i = i + K - 1;
            }
            min_res = min(min_res, res);
        }

        cout << min_res << "\n";
    }
}