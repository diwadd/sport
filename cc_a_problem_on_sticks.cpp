#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
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
    
        set<int> numbers;
        bool is_zero = false;
        for(int i = 0; i < N; i++) {
            numbers.insert(a_vec[i]);
            if(a_vec[i] == 0) {
                is_zero = true;
            }
        }
    
        int res = numbers.size();
        if(is_zero == true)
            res = res - 1;

        cout << res << "\n";
    }
}