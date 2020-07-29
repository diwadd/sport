#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

const int N_LETTERS = 26;
int N_LEAFS = 1000000;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {

        int N;
        cin >> N;

        vector<int> h_vec(N, 0);
        for(int n = 0; n < N; n++) {
            int h;
            cin >> h;
            h_vec[n] = h;
        }

        int peaks = 0;
        for(int n = 1; n < N-1; n++) {
            if(h_vec[n] > h_vec[n-1] && h_vec[n] > h_vec[n+1]){
                peaks++;
            }
        }

        cout << "Case #" << t << ": " << peaks << "\n";
    }
}