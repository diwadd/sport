#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

template<typename T> void print_vector(vector<T> &vec) {
    for(auto v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}

void print_map(map<int, int> &m) {
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

        lli N;
        lli x;
        scanf("%lld %lld", &N, &x);

        vector<lli> vec(N, 0);
        for(int i = 0; i < N; i++) {
            lli a;
            scanf("%lld", &a);
            vec[i] = a;
        }

        sort(vec.begin(), vec.end());
        lli total_days = 0;
        lli missed_cities = 0;

        for(int i = 0; i < N; i++) {
            lli a = vec[i];

            if(a <= x) {

                if( 2 * a < x ) {
                    missed_cities++;
                    continue;  
                }

                if( 2 * a >= x ) {
                    x = 2 * a;
                    total_days += 1;
                    continue;
                }
            }

            long double ratio = a / x;
            lli c;
            if (ratio  < 1.0) {
                c = 0;
            } else {
                c = floor(log2(ratio));
            }

            if( i == N - 1 ) {
                if( pow(2, c)*x >= a ) {
                    x = 2 * a;
                    total_days += c + 1;
                    continue;
                }

                total_days += c + 2;
                continue;


            }


            if( pow(2, c)*x >= a ) {
                x = 2 * a;
                total_days += c + 1;
                continue;
            }

            if( pow(2, c+1)*x >= a ) {
                x = 2 * a;
                total_days += c + 2;
                continue;
            } else {
                missed_cities++;
                continue;
            }


        }

        total_days += missed_cities;
        printf("%lld\n", total_days);
    }
}