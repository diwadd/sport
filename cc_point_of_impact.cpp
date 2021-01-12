#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

vector<pair<int, int>> get_points(int N, int x, int y) {

    int NUMBER_OF_POINTS = 4;
    vector<pair<int,int>> points;
    points.reserve(NUMBER_OF_POINTS);
    if(x > y) {
        // Point number one
        int b_1 = y - x;
        int x_1 = N;
        int y_1 = x_1 + b_1;

        // Point number two
        int b_2 = y_1 + x_1;
        int y_2 = N;
        int x_2 = b_2 - y_2;

        // Point number three
        int b_3 = y_2 - x_2;
        int x_3 = 0;
        int y_3 = x_3 + b_3;

        // Point number four
        int b_4 = y_3 + x_3;
        int y_4 = 0;
        int x_4 = b_4 - y_4;

        points.push_back(make_pair(x_1, y_1));
        points.push_back(make_pair(x_2, y_2));
        points.push_back(make_pair(x_3, y_3));
        points.push_back(make_pair(x_4, y_4));
    } else {

        // Point number one
        int b_1 = y - x;
        int y_1 = N;
        int x_1 = y_1 - b_1;

        // Point number two
        int b_2 = y_1 + x_1;
        int x_2 = N;
        int y_2 = -x_2 + b_2;

        // Point number three
        int b_3 = y_2 - x_2;
        int y_3 = 0;
        int x_3 = y_3 - b_3;

        // Point number four
        int b_4 = y_3 + x_3;
        int x_4 = 0;
        int y_4 = -x_4 + b_4;

        points.push_back(make_pair(x_1, y_1));
        points.push_back(make_pair(x_2, y_2));
        points.push_back(make_pair(x_3, y_3));
        points.push_back(make_pair(x_4, y_4));
    }

    return points;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N, K, x, y;
        cin >> N >> K >> x >> y;

        if(x == y) {
            cout << N << " " << N << "\n";
            continue;
        }

        vector<pair<int, int>> points = get_points(N, x, y);

        int BOX_DIM = 4;
        int SHIFT = 3;
        int index = (K+SHIFT) % BOX_DIM;
        cout << points[index].first << " " << points[index].second << "\n";
    }
}