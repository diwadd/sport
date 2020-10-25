#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


void print_vector(vector<int> &vec) {

    for(auto v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}


int get_missing_point(vector<int> &vec){

        int mark = vec[0];
        int mark_parity = 1;
        for(int i = 1; i < vec.size(); i++) {

            if(vec[i] == mark) {
                mark_parity++;
                continue;
            } else {
                if(mark_parity % 2 == 0) {
                    mark = vec[i];
                    mark_parity = 1;
                } else {
                    // x coordinate of missing point found.
                    // It is guaranteed that such a point exists.
                    return mark;
                }
            }
        }

    // Last element
    if(mark_parity % 2 == 0) {
        return -1;
    } else {
        return mark;
    }


}


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N;
        cin >> N;

        vector<int> x_vec(4 * N - 1, 0);
        vector<int> y_vec(4 * N - 1, 0);
        for(int i = 0; i < 4 * N - 1; i++) {
            int x, y;
            cin >> x >> y;

            x_vec[i] = x;
            y_vec[i] = y;
        }

        sort(x_vec.begin(), x_vec.end());
        sort(y_vec.begin(), y_vec.end());

        // print_vector(x_vec);
        // print_vector(y_vec);

        int x_point = get_missing_point(x_vec);
        int y_point = get_missing_point(y_vec);

        cout << x_point << " " << y_point << "\n";
    }
}