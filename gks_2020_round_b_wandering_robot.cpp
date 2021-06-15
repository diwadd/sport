#include <bits/stdc++.h> 

using namespace std;
typedef long double ld;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int MAX_GRID_SIZE = 1000000 + 7;

    vector<ld> log_power_2(MAX_GRID_SIZE, 0.0);
    vector<ld> log_factorial(MAX_GRID_SIZE, 0.0);

    for(int i = 1; i < MAX_GRID_SIZE; i++) {
        log_power_2[i] = ld(i);
        log_factorial[i] = log_factorial[i-1] + log2(ld(i));
    }


    auto get_p = [&](int n, int k) -> ld {
        return pow(2, log_factorial[n] - log_factorial[k] - log_factorial[n-k] - log_power_2[n]);
    };

    // print_vector(log_power_2);
    // print_vector(log_factorial);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int W, H, L, U, R, D;
        cin >> W >> H >> L >> U >> R >> D;

        vector<pair<int, int>> valid_points;

        // Valid points above
        for(int i = 1; i < max(W, H); i++) {
            int x = L - i;
            int y = D + i;

            if(x < 1 || y > H)
                break;
            
            auto p = make_pair(L - i, D + i);
            valid_points.push_back(p);
        }

        // Valid points below
        for(int i = 1; i < max(W, H); i++) {
            int x = R + i;
            int y = U - i;

            if(x > W || y < 1)
                break;
            
            auto p = make_pair(R + i, U - i);
            valid_points.push_back(p);
        }

        ld res = 0.0;

        for(int i = 0; i < valid_points.size(); i++) {

            auto point = valid_points[i];
            int x = point.first;
            int y = point.second;

            ld p = 0.0;

            if(x == W) {

                int xi = x - 1;
                int yi = y;

                while(yi >= 1) {
                    ld g = get_p(xi + yi - 2, xi - 1);
                    // cout << "---> " << "xi: " << xi << " yi: " << yi << " g: " << g << "\n";
                    p += g;
                    yi--;
                }
                p = p / 2.0;
            } else if(y == H) {

                int xi  = x;
                int yi = y - 1;

                while(xi >= 1) {
                    ld g = get_p(xi + yi - 2, yi - 1);
                    // cout << "---> " << "xi: " << xi << " yi: " << yi << " g: " << g << "\n";
                    p += g;
                    xi--;
                }
                p = p / 2.0;
            } else {
                p = get_p(x + y - 2, x - 1);
            }

            // cout << "x: " << x << " y: " << y << " probability: " << p << "\n";

            res += p;
        }

        cout << "Case #" << t+1 << ": " << setprecision(20) << res << "\n";
        // cout << setprecision(20) << res << "\n";
    }
}