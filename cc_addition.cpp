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


int bit_addition(int &a, int &b) {

    std::bitset<MAX_BITS> ab(a);
    std::bitset<MAX_BITS> bb(b);
    // cout << ab << endl; 
    // cout << bb << endl; 

    int index = 0;
    while(b>0){
        //cout << "index: " << index << endl;
        int u = a ^ b;
        int v = a & b;
        a = u;
        b = v * 2;
        // std::bitset<MAX_BITS> ub(u);
        // std::bitset<MAX_BITS> vb(v);
        // std::bitset<MAX_BITS> ab(a);
        // std::bitset<MAX_BITS> bb(b);

        // cout << "u: " << ub << endl;    
        // cout << "v: " << vb << endl; 
        // cout << "a: " << ab << endl; 
        // cout << "b: " << bb << endl; 
        index++;
    }
    return index;
}


int number_of_whiles(bitset<MAX_BITS> &a_bits, bitset<MAX_BITS> &b_bits) {

    if(b_bits == 0)
        return 0;

    bitset<MAX_BITS> and_ab = a_bits & b_bits; 
    //cout << "xor_ab: " << xor_ab << endl;
    //cout << "and_ab: " << and_ab << endl;

    if(and_ab == 0)
        return 1;

    bitset<MAX_BITS> xor_ab = a_bits ^ b_bits;

    int max_number_of_ones = 0;
    int one_counter = 0;
    for(size_t i = MAX_BITS; i > 0; i--) {
        //cout << "i = " << i << " xor_ab[i]: " << xor_ab[i] << " and_ab[i-1]: " << and_ab[i-1] << endl;
        if (xor_ab[i] == 1 & and_ab[i-1] == 0){
            one_counter++;
        } else if (xor_ab[i] == 1 & and_ab[i-1] == 1){
            one_counter++;
            //cout << "one counter: " << one_counter << " max_number_of_ones: " << max_number_of_ones << endl;
            if(one_counter > max_number_of_ones){
                max_number_of_ones = one_counter;
                one_counter = 0;
            }
        } else if (xor_ab[i] == 0 & and_ab[i-1] == 0) {
            one_counter = 0;
        }


    }

    return max_number_of_ones + 2;
}


int main() {
 



    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        string as;
        string bs;

        //int as;
        //int bs;
        cin >> as;
        cin >> bs;
        // int a = stoi(as, nullptr, 2);
        // int b = stoi(bs, nullptr, 2);

        bitset<MAX_BITS> a_bits(as);
        bitset<MAX_BITS> b_bits(bs);  

        // cout << "a_bits: " << a_bits << " -> " << (int)(a_bits.to_ulong()) << endl;
        // cout << "b_bits: " << b_bits << " -> " << (int)(b_bits.to_ulong()) << endl;

        //int res = bit_addition(as, bs);
        //printf("bit_addition res: %d\n", res);  

        int res = number_of_whiles(a_bits, b_bits);
        //printf("number_of_whiles res: %d\n", res);
        printf("%d\n", res);
    }

    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<> dis(0, 30000000);
    // for(int i = 0; i < 10; i++){
    //     int a = dis(gen);
    //     int b = dis(gen);
    //     int a_backup = a;
    //     int b_backup = b;

    //     bitset<MAX_BITS> a_bits(a);
    //     bitset<MAX_BITS> b_bits(b);
        
    //     //chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    //     int res_1 = bit_addition_original(a, b);
    //     //chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //     //cout << "Elapsed time in bit_addition = " << chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << endl;

    //     //begin = std::chrono::steady_clock::now();
    //     int res_2 = number_of_whiles(a_bits, b_bits);
    //     //end = std::chrono::steady_clock::now();
    //     //cout << "Elapsed time in number_of_whiles = " << chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << endl;


    //     if (res_1 != res_2)
    //         printf("a: %d b: %d res_1: %d res_2: %d\n", a_backup, b_backup, res_1, res_2);
    //     else
    //         printf("a: %d b: %d OK!\n", a_backup, b_backup);            

    // }

}