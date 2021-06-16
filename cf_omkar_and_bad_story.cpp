#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;
        vector<int> a_vec(N, 0);


        bool is_ok = true;
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
            if(a_vec[i] < 0) {
                is_ok = false;
            }
        }

        if(is_ok == false) {
            cout << "NO\n";
            continue;
        } else {

            cout << "YES\n101\n";
            for(int i = 0 ; i <= 100; i++) {
                if(i != 100) {
                    cout << i << " ";
                } else {
                    cout << i << "\n";
                }
            }

        }
    }
}