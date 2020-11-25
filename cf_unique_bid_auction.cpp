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
        map<int, int> freq;
        map<int, int> index_mapping;
 
        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            freq[a]++;
 
            if(freq[a] <= 1) {
                index_mapping[a] = i;
            }
        }
 
        
 
        int index = -1;
        int min_a = numeric_limits<int>::max();
        for(auto it = freq.begin(); it != freq.end(); it++) {
            if(it->second == 1 && it->first < min_a) {
                index = index_mapping[it->first];
                min_a = it->first;
            }
        }
 
        if(index == -1)
            cout << "-1\n"; 
        else
            cout << index+1 << "\n";
    }
}
 
 