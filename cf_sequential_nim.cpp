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
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;
 
        vector<int> a_vec(N,0);
        for(int n = 0; n < N; n++) {
            int a;
            cin >> a;
            a_vec[n] = a;
        }
 
        vector<int> ones(N, 0);
        if(a_vec[N-1] == 1)
            ones[N-1] = 1;
 
        for(int i = N - 2; i >= 0; i--) {
            if(a_vec[i] == 1) {
                ones[i] = ones[i + 1] + 1;
            } else {
                ones[i] = 0;
            }
        }
 
        int player = 1;
        bool last_one_shift = false;
        for(int i = 0; i < N-1; i++) {
            if(a_vec[i] == 1) {
                if(player == 1)
                    player = 2;
                else
                    player = 1;
            }
 
            if(a_vec[i] > 1 && ones[i+1] == 0) {
                continue;
            }
 
            if(a_vec[i] > 1 && ones[i+1] > 0) {
                
                int last_one_index = i + ones[i+1];
                if(last_one_index == N - 1) {
                    last_one_shift = true;
                    if(player == 1)
                        player = 2;
                    else
                        player = 1;
                    break;
                } else if (last_one_index != N - 1) {
                    if(ones[i+1] % 2 == 0) {
                        continue;
                    } else {
                        if(player == 1)
                            player = 2;
                        else
                            player = 1; 
                    }

                }
 
            }
        }
 
        if(a_vec[N-1] == 1 && last_one_shift == true) {
            if(player == 1)
                player = 2;
            else
                player = 1;
        }
 
        if(player == 2)
            cout << "Second\n";
        else
            cout << "First\n";
 
 
    }
}