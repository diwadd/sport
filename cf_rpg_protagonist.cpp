#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

void swap_values(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int p, f, cnt_s, cnt_w, s_weight, w_weight;
        cin >> p >> f >> cnt_s >> cnt_w >> s_weight >> w_weight;

        if(s_weight > w_weight) {
            swap_values(s_weight, w_weight);
            swap_values(cnt_s, cnt_w);
        }

        int res = 0;
        int res_p = 0;
        int res_f = 0;
        for(int s = 0; s <= min(cnt_s, p / s_weight); s++) {

            int w = min(cnt_w, (p - s * s_weight) / w_weight);
            int s_f = min(cnt_s - s, f / s_weight);
            int w_f = min(cnt_w - w , (f - s_f * s_weight) / w_weight);

            if(s * s_weight + w * w_weight <= p && s_f * s_weight + w_f * w_weight <= f) {
                res = max(res, s + w + s_f + w_f);
            }
        }

        cout << res << "\n";

    }
}