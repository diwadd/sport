#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int t;
    scanf("%d", &t);

    int n_k_twos = 30;
    vector<int> vec(n_k_twos, 0);

    for(int i = 0; i < n_k_twos; i++) {
        vec[i] = (int)pow(2, i) - 1;
    }

    for(int i = 0; i < t; i++) {

        int n;
        scanf("%d", &n);

        for(int j = 2; j < vec.size(); j++) {
            if(n % vec[j] == 0) {
                printf("%d\n", n/vec[j]);
                break;
            }
        }

    }
}