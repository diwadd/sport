#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;

template<typename T> void print_vector(vector<T> &v){

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    const int MAX_BITS = 21;
    // vector<bitset<MAX_BITS>> vec(N, 0);

    vector<int> bit_count(MAX_BITS, 0);
    for(int n = 0; n < N; n++) {
        int a;
        cin >> a;

        //vec[n] = bitset<MAX_BITS>(a);
        bitset<MAX_BITS> a_as_bits(a);

        for(int i = 0; i < a_as_bits.size(); i++) {
            if(a_as_bits[i] == 1) {
                 bit_count[i]++;
            }
        }
    }


    // print_vector(bit_count);

    ulli sum = 0;
    while(true) {

        bitset<MAX_BITS> number(0);
        for(int i = 0; i < bit_count.size(); i++) {
            if(bit_count[i] > 0) {
                number[i] = 1;
                bit_count[i]--;
            }
        }

        if(number.to_ullong() == 0)
            break;

        sum = sum + number.to_ullong()*number.to_ullong();
    }

    cout << sum << "\n";
}