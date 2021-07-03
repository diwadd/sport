#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N;
        cin >> N;

        vector<int> a_vec(N+1, 0);
        for(int i = 1; i <= N; i++) {
            cin >> a_vec[i];
        }

        vector<pair<int, int>> location;
        location.reserve(N+1);

        for(int i = 1; i <= N; i++) {
            location.push_back(make_pair(a_vec[i], i));
        }

        auto comp = [](auto &l, auto &r) {
                        return l.first < r.first;
                    };

        sort(location.begin(), location.end(), comp);

        // for(auto &loc : location) {
        //     cout << loc.first << " " << loc.second << endl;
        // }

        int res = 0;
        int MAX_I_PLUS_J = 2*N;
        for(int i = 1; i <= N; i++) {

            for(int j = 0; j < location.size(); j++) {
                int aj = location[j].first;
                int index = location[j].second;

                if(a_vec[i] * aj > MAX_I_PLUS_J)
                    break;
                if(i < index && a_vec[i] * aj == i + index) {
                    res++;
                }
            }
        }

        cout << res << "\n";
    }
}
