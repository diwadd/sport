#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


void print_pair(pair<int, int> &p) {

    cout << p.first << " " << p.second << "\n";
}

void shift_cell_by(pair<int, int> &cell, int dx, int dy) {

    cell.first = cell.first + dx;
    cell.second = cell.second + dy;

}


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    cout << 6 + N + 2*(N-1) << "\n";

    pair<int, int> south_west = {0, 0};
    pair<int, int> south_east = {0, 1};
    pair<int, int> north_west = {1, 0};
    pair<int, int> north_east = {1, 1};

    print_pair(south_west);
    print_pair(south_east);
    print_pair(north_east);
    print_pair(north_west); 


    for(int n = 0; n < N; n++) {

        shift_cell_by(south_west, -1, -1);
        shift_cell_by(south_east, -1, -1);
        shift_cell_by(north_west, -1, -1);

        print_pair(south_west);
        print_pair(south_east);
        print_pair(north_west);

    }

}