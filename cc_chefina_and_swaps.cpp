#include <bits/stdc++.h> 

using namespace std;
typedef long long int ulli;

template <typename T> void print_vector(vector<T> &vec) {
    for(auto v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}

template <typename T> void print_map(map<T, T> &m) {
    cout << "Printing map:" << endl;
    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " <-> " << it->second << "\n";
    }
}

int main() {

    const unsigned long long MOD7 = 1000000000+7;
    const unsigned long long MAX_NUMBERS = 200000 + 7;

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T;
    // cin >> T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++) {

        int N;
        scanf("%d", &N);

        vector<int> a_vec(N, 0);
        vector<int> b_vec(N, 0);

        map<ulli, ulli> a_map;
        map<ulli, ulli> b_map;
        map<ulli, ulli> full_map;

        ulli minimal_element = numeric_limits<ulli>::max();
        for(int i = 0; i < N; i++) {
            ulli a;
            scanf("%lld", &a);
            a_vec[i] = a;
            ++a_map[a];
            ++full_map[a];

            if(a < minimal_element)
                minimal_element = a;
        }

        for(int i = 0; i < N; i++) {
            ulli b;
            scanf("%lld", &b);
            b_vec[i] = b;
            ++b_map[b];
            ++full_map[b];

            if(b < minimal_element)
                minimal_element = b;
        }

        // cout << "Minimal element: " << minimal_element << endl;

        bool is_ok = true;
        map<ulli, ulli> optimal;

        for(auto it = full_map.begin(); it != full_map.end(); it++) {
            if(it->second % 2 != 0) {
                is_ok = false;
                break;
            }
            full_map[it->first] = (it->second)/2;
        }

        if(is_ok == false) {
            printf("-1\n");
            continue;
        }

        vector<ulli> a_vec_swap;
        vector<ulli> b_vec_swap;

        for(auto it = a_map.begin(); it != a_map.end(); it++) {
            ulli delta = full_map[it->first] - it->second;
            // cout << "delta: " << delta << endl;
            if(delta < 0) {
                for(int i = 0; i < abs(delta); i++) {
                    a_vec_swap.push_back(it->first);
                }
            }
        }

        for(auto it = b_map.begin(); it != b_map.end(); it++) {
            ulli delta = full_map[it->first] - it->second;
            if(delta < 0) {
                for(int i = 0; i < abs(delta); i++) {
                    b_vec_swap.push_back(it->first);
                }
            }
        }

        sort(a_vec_swap.begin(), a_vec_swap.end());
        sort(b_vec_swap.rbegin(), b_vec_swap.rend());

        // print_vector(a_vec_swap);
        // print_vector(b_vec_swap);

        ulli cost = 0;
        for(int i = 0; i < a_vec_swap.size(); i++) {
            cost = cost + min(2*minimal_element, min(a_vec_swap[i], b_vec_swap[i]));
        }

        printf("%lld\n", cost);
    }
}