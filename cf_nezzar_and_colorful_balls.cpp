#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t_ = 0; t_ < T; t_++) {
        
        int N;
        cin >> N;

        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }

        vector<int> colors(N, 0);
        int color_val = 1;
        for(int i = 0; i < N; i++) {
            int c;
            if(colors[i] == 0) {
                colors[i] = color_val;
                c = a_vec[i];
            } else {
                continue;
            }
            for(int j = i+1; j < N; j++) {
                if(colors[j] == 0 && a_vec[j] > c) {
                    colors[j] = color_val;
                    c = a_vec[j];
                }
            }
            color_val++;
        }

        cout << color_val - 1 << "\n";
    }
}
