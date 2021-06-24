#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        lli N;
        cin >> N;

        vector<int> a_vec(N, 0);
        lli sum = 0;
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
            sum += a_vec[i];
        }

        if(sum == N){
            cout << "0\n";
        } else if(sum < N) {
            cout << "1\n";
        } else {
            cout << (sum - N) << "\n";
        }

    }


}