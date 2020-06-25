#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;

void n_odd(int &N) {

    int index = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {

            if (j < N) {
                printf("%d ", index);
                ++index;
            } else {
                printf("%d\n", index);
                ++index;
            }
        }
    }
}


void n_even(int &N) {

    int odd_index = 1;
    int even_index = 2;
    bool odd_token = true;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {

            if (j < N) {

                if( (i + j) % 2 == 0) {
                    printf("%d ", odd_index);
                    odd_index += 2;
                } else {
                    printf("%d ", even_index);
                    even_index += 2;
                }

            } else {

                if( (i + j) % 2 == 0) {
                    printf("%d\n", odd_index);
                    odd_index += 2;
                } else {
                    printf("%d\n", even_index);
                    even_index += 2;
                }

            }
        }
    }
}


int main() {


    int T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);

        if(N % 2 != 0) {
            n_odd(N);
        } else {
            n_even(N);
        }

    }



}