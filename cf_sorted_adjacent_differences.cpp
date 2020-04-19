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

        sort(vec.begin(), vec.end());

        int center = 0;
        
        if(n % 2 == 0) {
            center = n/2 - 1;
        } else {
            center = n/2;
        }

        vector<int> new_order(n, 0);
        int index = 0;
        int shift = 1;
        int shift_s = pow(-1, index)*shift;
        while(index < n){

            new_order[index] = vec[center];


            shift_s = pow(-1, index)*shift;
            shift = shift + 1;
            center = center + shift_s;
            index = index + 1;

        }


        for(auto it = new_order.begin(); it < new_order.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");

    }
}