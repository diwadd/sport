#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N, K;
        cin >> N >> K;

        vector<pair<int,int>> points(N, pair<int,int>());
        for(int n = 0; n < N; n++) {
            int x, y;
            cin >> x >> y;
            points[n].first = x;
            points[n].second = y;
        }

        bool found_point = false;
        for(int i = 0; i < N; i++) {
            int x1 = points[i].first;
            int y1 = points[i].second;

            bool is_ok = true;
            for(int j = 0; j < N; j++) {

                if(i == j)
                    continue;

                int x2 = points[j].first;
                int y2 = points[j].second;

                int d = abs(x1 - x2) + abs(y1 - y2);
                if(d > K) {
                    is_ok = false;
                    break;
                }

            }

            if(is_ok == true) {
                found_point = true;
                break;
            }
        }


        if(found_point == true) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }

    }

}