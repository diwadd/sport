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
 
    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;
 
        string s;
        cin >> s;
 
        vector<int> s_vec(N, 0);
        for(int i = 0; i < N; i++) {
            if(s[i] == '1')
                s_vec[i] = 1;
        }
 
        vector<int> seen_vec(N, 0);
        int n_seen = 0;
 
        vector<int> c_vec(N, -1);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(s_vec[i] != c_vec[j]) {
                    c_vec[j] = s_vec[i];
                    seen_vec[i] = j;
                    break;
                }
            }
        }

        // print_vector(seen_vec);

        auto it = max_element(begin(seen_vec), end(seen_vec)); 
        for(int i = 0; i < N; i++)
            seen_vec[i] += 1;
 
        cout << *it << "\n";
        print_vector(seen_vec);
    }
}