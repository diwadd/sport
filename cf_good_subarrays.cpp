#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;

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
 
    for(int t = 1; t <= T; t++) {
 
        int N;
        cin >> N;

        string s;
        cin >> s;
 
        vector<int> s_vec(N, 0);
        for(int i = 0; i < N; i++) {
            s_vec[i] = int(s[i] - '0') - 1;
        }

        map<lli, lli> freq;

        vector<int> prefix_array(N+1, 0);
        for(int i = 1; i < N+1; i++) {
            prefix_array[i] = prefix_array[i-1] + s_vec[i-1];
        }
 
        // print_vector(prefix_array);

        for(int i = 0; i < N+1; i++) {
            freq[prefix_array[i]]++;
        }
 
        lli res = 0;
        for(auto it = freq.begin(); it != freq.end(); it++) {
            res += it->second * (it->second - 1) / 2;
        }

        cout << res << "\n";

    }
}