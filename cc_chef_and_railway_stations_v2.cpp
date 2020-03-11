#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;
typedef unsigned long long int ulli;

int N_MAX = 1e5+1;
vector<int> sieve(N_MAX, 0);

vector<pair<long long int,long long int>> get_primes(long long int x){

    vector<pair<long long int, long long int>> primes;

    while(x > 1) {
        int p = sieve[x];
        int c = 0;
        while(x % p == 0){
            x = x / p;
            c++;
        }
        primes.push_back(make_pair(p, c));
    }

    if (x > 1) {
        primes.push_back(make_pair(x, 1));  
    }
    return primes;
}

vector<long long int> get_divisors(long long int index, long long int divisor, vector<pair<long long int,long long int>> &primes){

    vector<long long int> divs;
    if (index == primes.size()){
        //cout << "divisor: " << divisor << endl;
        divs.push_back(divisor);
        return divs;
    }

    for(long long int i = 0; i < 2*primes[index].second + 1; i++) {
        // cout << "i: " << i << endl;
        vector<long long int> v = get_divisors(index+1, divisor, primes);
        divs.insert(divs.end(), v.begin(), v.end());
        divisor = divisor * primes[index].first;
    }
}


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i < N_MAX; i++) {
        if(sieve[i] == 0){
            for(int j = 0; (j+=i)<=N_MAX; ){
				sieve[j]=i;
            }
        }
    }
    sieve[0] = 1;
    sieve[1] = 1;

    long long int t;
    cin >> t;    
    for(long long int i = 0; i < t; i++){

        long long int n, m;
        cin >> n >> m;

        vector<long long int> v_seen_xs_pos(N_MAX, 0);
        vector<long long int> v_seen_ys_pos(N_MAX, 0);

        vector<long long int> v_seen_xs_neg(N_MAX, 0);
        vector<long long int> v_seen_ys_neg(N_MAX, 0);

        vector<long long int> x_pos_v;
        vector<long long int> x_neg_v;

        vector<long long int> y_pos_v;
        vector<long long int> y_neg_v;

        map<long long int, long long int> x_map;
        map<long long int, long long int> y_map;

        long long int n_x_pos = 0;
        long long int n_x_neg = 0;

        bool zero_in_xs = false;
        for(long long int j = 0; j < n; j++){
            long long int xj;
            cin >> xj;

            //x_polong long ints[j] = xj;
            long long int x2 = abs(xj);
            if(x_map.find(x2) != x_map.end()){
                x_map[x2] = x_map[x2] + 1;
            } else {
                x_map[x2] = 1;
            }

            if (xj == 0) {
                zero_in_xs = true;
            }

            if (xj > 0) {
                n_x_pos++;
                v_seen_xs_pos[x2] = 1;
                //x_pos_v.push_back(xj);
            } else if (xj < 0) {
                n_x_neg++;
                v_seen_xs_neg[x2] = 1;
                //x_neg_v.push_back(-xj);
            }
        }

        long long int n_y_pos = 0;
        long long int n_y_neg = 0;
        
        bool zero_in_ys = false;
        for(long long int j = 0; j < m; j++){
            long long int yj;
            cin >> yj;

            //y_polong long ints[j] = yj;
            long long int y2 = abs(yj);
            if(y_map.find(y2) != y_map.end()){
                y_map[y2] = y_map[y2] + 1;
            } else {
                y_map[y2] = 1;
            }

            if (yj == 0) {
                zero_in_ys = true;
            }

            if (yj > 0) {
                n_y_pos++;
                v_seen_ys_pos[y2] = 1;
            } else if (yj < 0) {
                n_y_neg++;
                v_seen_ys_neg[y2] = 1;
            }
        }

        long long int q_ne = 0;
        long long int q_se = 0;
        long long int q_nw = 0;
        long long int q_sw = 0;
        long long int res = 0;

        //cout << " --- --- --- --- --- --- --- " << endl;
        if (zero_in_xs == true || zero_in_ys == true){

                q_ne = n_x_pos*n_y_pos;
                q_se = n_x_pos*n_y_neg;

                q_nw = n_x_neg*n_y_pos;
                q_sw = n_x_neg*n_y_neg;
        }

        res = res + q_ne + q_se + q_nw + q_sw;

        bool x_y_p_n = n_x_pos == 0 && n_y_neg == 0;
        bool x_y_n_p = n_x_neg == 0 && n_y_pos == 0;
        bool x_y_n_n = n_x_neg == 0 && n_y_neg == 0;
        bool x_y_p_p = n_x_pos == 0 && n_y_pos == 0;

        if(x_y_n_n == true || x_y_n_p == true || x_y_p_p == true || x_y_p_n == true) {
            cout << res << endl;
            continue;
        }


        map<long long int, vector<long long int>> number_factors;

        long long int max_ele = 122;
        map<long long int, long long int>::iterator it; 
        for(it = x_map.begin(); it != x_map.end(); it++){

            long long int x = it->first;
            if(x == 0)
                continue;

            vector<long long int> *divs;
            if(number_factors.find(x) == number_factors.end()) {
                vector<pair<long long int, long long int>> primes = get_primes(x); 
                number_factors[x] = get_divisors(0, 1, primes);
                divs = &number_factors[x];
            } else {
                divs = &number_factors[x];
            }

            vector<long long int>::iterator its;
            for(its = (*divs).begin(); its != (*divs).end(); its++) {

                long long int d1 = *its;
                long long int d2 = (x*x)/(*its);

                if(d1 <= N_MAX && d2 <= N_MAX) {
                    if(v_seen_ys_neg[d1] == 1 && v_seen_ys_pos[d2] == 1){
                        res = res + it->second;
                    }
                }

            }
        }


        // Trinagles in y
        //cout << "Checking ys..." << endl;
        for(it = y_map.begin(); it != y_map.end(); it++){

            long long int y = it->first;
            if(y == 0)
                continue;


            vector<long long int> *divs;
            if(number_factors.find(y) == number_factors.end()) {
                vector<pair<long long int, long long int>> primes = get_primes(y); 
                number_factors[y] = get_divisors(0, 1, primes);
                divs = &number_factors[y];
            } else {
                divs = &number_factors[y];
            }

            vector<long long int>::iterator its;
            for(its = (*divs).begin(); its != (*divs).end(); its++) {

                long long int d1 = *its;
                long long int d2 = (y*y)/(*its);

                if(d1 <= N_MAX && d2 <= N_MAX) {
                    if(v_seen_xs_neg[d1] == 1 && v_seen_xs_pos[d2] == 1){
                        res = res + it->second;
                    }
                }

            }
        }


        cout << res << endl;
    }
}