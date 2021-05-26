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

        vector<int> vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> vec[i];
        }

        int res = 0;
        vector<int> seen(N, 0);
        for(int i = 0; i < N; i++) {

            if(seen[i] == 1)
                continue;

            map<int, int> freq;
            int ele_sum = 0;
            for(int j = i; j < N; j += K) {
                if(freq.find(vec[i]) != freq.end()) {
                    freq[vec[j]]++;
                } else {
                    freq[vec[j]] = 1;
                }
                seen[j] = 1;
                ele_sum++;
            }

            int max_val = numeric_limits<int>::min();
            int max_key = 0;
            for(auto it = freq.begin(); it != freq.end(); it++) {
                if(it->second > max_val) {
                    max_val = it->second;
                    max_key = it->first;
                }
            }

            res += (ele_sum - max_val);
        }

        cout << res << "\n";

    }




}