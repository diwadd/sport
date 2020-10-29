#include <bits/stdc++.h> 
 
using namespace std;
typedef unsigned long long int ulli;
 
 
void print_vector(vector<int> &vec) {
 
    for(auto v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}
 
int main() {
 
    const unsigned long long MOD7 = 1000000000 + 7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
 

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int n;
        cin >> n;
 
        if(n == 1) {
            cout << "FastestFinger\n";
            continue;
        } 

        if(n == 2) {
            cout << "Ashishgup\n"; 
            continue;    
        }

        if(n % 2 != 0) {
            cout << "Ashishgup\n"; 
            continue;
        }
 
        int number_of_twos = 0; 
        while(n % 2 == 0){
            n = n / 2;
            number_of_twos++;
        }

        // This means that n was equal to 2^m
        if(n == 1){
            cout << "FastestFinger\n";
            continue;
        }

        if(number_of_twos > 1) {
            cout << "Ashishgup\n";
            continue; 
        }

        bool is_prime = true;
        for(int i = 3; i*i <= n; i++) {
            if(n % i == 0){
                is_prime = false;
                break;
            }
        }

        if(is_prime == true) {
            cout << "FastestFinger\n";
        } else {
            cout << "Ashishgup\n"; 
        }



    }
 
}