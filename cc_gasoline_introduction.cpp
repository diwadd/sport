#include <bits/stdc++.h> 
// #include <numeric>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t_ = 0; t_ < T; t_++) {
 
        int N;
        cin >> N;

        vector<int> f_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> f_vec[i];
        }

        int fuel = 0;
        int steps = 0;
        for(int i = 0; i < N; i++) {
            
            fuel += f_vec[i];
            
            if(fuel > 0) {
                fuel--;
                steps++;
            } else {
                break;
            }
        }

        cout << steps + fuel << "\n";

    }
}
