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
    for(int i = 0; i < t; i++) {

        int n;
        scanf("%d", &n);
        vector<int> vec(n, 0);
        for(int j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            vec[j] = a;
        }

        int max_k = 0;
        for(int j = 1; j < n; j++) {


            if(vec[j] >= vec[j-1]) {
                continue;
            }

            int delta = vec[j-1] - vec[j];
            int k = (int)log2(delta);

            vec[j] = vec[j] + delta;
            if(k + 1 > max_k) {
                max_k = k + 1;
            }

        }
        printf("%d\n", max_k);

    }
}