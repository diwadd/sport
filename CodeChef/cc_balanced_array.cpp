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

        if((n/2) % 2 != 0) {
            printf("NO\n");
            continue;
        }

        vector<int> vec(n, 0);

        int index = 0;
        for(int j = n/2; j < n; j++) {
            vec[j] = 2*index + 1;
            index = index + 2;
        }


        for(int j = 0; j < n/4; j++) {
            vec[j] = vec[n/2 + j] + 1;
        }


        for(int j = n/4; j < n/2; j++) {
            vec[j] = vec[n/2 + j] - 1;
        }

        printf("YES\n");
        for(int j = 0 ; j < vec.size(); j++) {
            printf("%d ", vec[j]);
        }
        printf("\n");

    }
}