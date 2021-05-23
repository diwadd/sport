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

        int G, P;
        cin >> G >> P;

        int NG = 10;
        vector<int> X(NG+1, 0);
        for(int i = 1; i <= NG; i++) {
            cin >> X[i];
        }

        vector<int> post_sum(NG+1, 0);
        post_sum[NG] = X[NG];
        for(int i = NG - 1; i >= 1; i--) {
            post_sum[i] = post_sum[i+1] + X[i];
        }

        if(G == NG) {
            if(post_sum[G] <= P) {
                cout << "1 1\n";
            } else {

                int days_in_g = X[G] / P;
                int left_overs_on_g = X[G] % P;

                int max_days;
                if(left_overs_on_g == 0)
                    max_days = days_in_g;
                else
                    max_days = days_in_g + 1;

                cout << "1 " << max_days << "\n";
            }
        } else {

            int days = post_sum[G+1] / P;
            int left_overs_the_day_before = post_sum[G+1] % P;

            if(left_overs_the_day_before == 0) {
                if(post_sum[G] <= P) {
                    cout << days+1 << " " << days+1 << "\n";
                } else {

                    int days_in_g = X[G] / P;
                    int left_overs_on_g = X[G] % P;

                    int max_days;
                    if(left_overs_on_g == 0)
                        max_days = days_in_g;
                    else
                        max_days = days_in_g + 1;

                    cout << days+1 << " " << days+max_days << "\n";
                }
            } else {

                X[G] += left_overs_the_day_before;

                int days_in_g = X[G] / P;
                int left_overs_on_g = X[G] % P;

                int max_days;
                if(left_overs_on_g == 0)
                    max_days = days_in_g;
                else
                    max_days = days_in_g + 1;

                cout << days+1 << " " << days+max_days << "\n";

            }
        }
    }
}