#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <random>
#include <chrono>

constexpr int MAX_BITS = 100005;
using namespace std;


int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 0; i < t; i++){
        string as;
        string bs;

        cin >> as;
        cin >> bs;

        bitset<MAX_BITS> a_bits(as);
        bitset<MAX_BITS> b_bits(bs);  

        if(b_bits == 0) {
            cout << 0 << endl;
            continue;
        }

        bitset<MAX_BITS> and_ab = a_bits & b_bits; 
        //cout << "xor_ab: " << xor_ab << endl;
        //cout << "and_ab: " << and_ab << endl;

        if(and_ab == 0) {
            cout << 1 << endl;
            continue;
        }

        bitset<MAX_BITS> xor_ab = a_bits ^ b_bits;

        int na = as.length();
        int nb = bs.length();

        int start = MAX_BITS;
        if(na > nb)
            start = na + 1;
        else
            start = nb + 1;

        int max_number_of_ones = 0;
        int one_counter = 0;

        for(int j = start; j > 0; --j) {
            //cout << "i = " << i << " xor_ab[i]: " << xor_ab[i] << " and_ab[i-1]: " << and_ab[i-1] << endl;
            if (xor_ab[j] == 1 && and_ab[j-1] == 0){
                ++one_counter;
            } else if (xor_ab[j] == 1 && and_ab[j-1] == 1){
                ++one_counter;
                //cout << "one counter: " << one_counter << " max_number_of_ones: " << max_number_of_ones << endl;
                if(one_counter > max_number_of_ones){
                    max_number_of_ones = one_counter;
                    one_counter = 0;
                }
            } else if (xor_ab[j] == 0 && and_ab[j-1] == 0) {
                one_counter = 0;
            }


        }

        int res = max_number_of_ones + 2;
        cout << res << endl;
        
    }

}