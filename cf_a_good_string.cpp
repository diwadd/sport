#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;


int n_to_make_good_string(char c, int left, int right, string &s) {

    int delta = right - left;
    if(delta == 1){
        if(s[left] == c){
            return 0;
        } else {
            return 1;
        }
    }

    int n_left_half = 0;
    int n_right_half = 0;
    int mid = left + (right - left) / 2;
    for(int i = left; i < mid; i++) {
        if(s[i] != c) {
            n_left_half++;
        }
    }

    for(int i = mid; i < right; i++) {
        if(s[i] != c) {
            n_right_half++;
        }
    }

    int left_sub_moves = n_to_make_good_string(c+1, left, mid, s);
    int right_sub_moves = n_to_make_good_string(c+1, mid, right, s);

    int total_moves_on_left_side = left_sub_moves + n_right_half;
    int total_moves_on_right_side = right_sub_moves + n_left_half;


    if(total_moves_on_left_side < total_moves_on_right_side) {
        return total_moves_on_left_side;
    } else {
        return total_moves_on_right_side;
    }
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
        
        int n_moves = n_to_make_good_string('a', 0, N, s);

        cout << n_moves << "\n";

    }
}