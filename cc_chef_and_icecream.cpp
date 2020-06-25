#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N;
        cin >> N;
        vector<int> customer_coins(N, 0);

        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            customer_coins[i] = a;
        }


        if(customer_coins[0] != 5) {
            cout << "NO" << "\n";
            continue;
        }

        int NUMBER_OF_COINS = 20;
        vector<int> chefs_coins(NUMBER_OF_COINS, 0);
        int COIN_FIVE = 5;
        int COIN_TEN = 10;
        int COIN_FIFTEEN = 15;
        chefs_coins[5]++;

        bool is_possible = true;
        for(int i = 1; i < N; i++) {

            int coin = customer_coins[i];

            int change = coin - 5;
            // printf("coin: %d change: %d\n", coin, change);

            if(change == 0) {
                chefs_coins[coin]++;
            } else if(change == COIN_FIVE) {
                
                if(chefs_coins[COIN_FIVE] > 0) {
                    chefs_coins[COIN_FIVE]--;
                    chefs_coins[coin]++;
                } else {
                    is_possible = false;
                    break;
                }

            } else if(change == COIN_TEN) {

                if(chefs_coins[COIN_TEN] > 0) {
                    chefs_coins[COIN_TEN]--;
                    chefs_coins[coin]++;
                } else if(chefs_coins[COIN_FIVE] >= 2) {
                    chefs_coins[COIN_FIVE]-=2;
                    chefs_coins[coin]++;
                } else {
                    is_possible = false;
                    break; 
                }

            } else {
                is_possible = false;
                break;
            }
        }


        if(is_possible == true) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }

    }
}